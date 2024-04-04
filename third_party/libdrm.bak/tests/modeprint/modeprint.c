/*************************************************************************
	> File Name: modeset-plane-test.c
	> Author: Arctan
	> Created Time: Wed 22 Jun 2022 05:25:12 AM PDT
 ************************************************************************/
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>


struct buffer_object {
	uint32_t width;
	uint32_t height;
	uint32_t pitch;
	uint32_t handle;
	uint32_t size;
	uint8_t *vaddr;
	uint32_t fb_id;
};

struct buffer_object buf;

static int modeset_create_fb(int fd, struct buffer_object *bo)
{
	struct drm_mode_create_dumb create = {};
 	struct drm_mode_map_dumb map = {};

	create.width = bo->width;
	create.height = bo->height;
	create.bpp = 32;
	drmIoctl(fd, DRM_IOCTL_MODE_CREATE_DUMB, &create);

	bo->pitch = create.pitch;
	bo->size = create.size;
	bo->handle = create.handle;
	drmModeAddFB(fd, bo->width, bo->height, 24, 32, bo->pitch,
			   bo->handle, &bo->fb_id);

	map.handle = create.handle;
	drmIoctl(fd, DRM_IOCTL_MODE_MAP_DUMB, &map);

	bo->vaddr = mmap(0, create.size, PROT_READ | PROT_WRITE,
			MAP_SHARED, fd, map.offset);

	memset(bo->vaddr, 0xff, bo->size);

	return 0;
}

static void modeset_destroy_fb(int fd, struct buffer_object *bo)
{
	struct drm_mode_destroy_dumb destroy = {};

	drmModeRmFB(fd, bo->fb_id);

	munmap(bo->vaddr, bo->size);

	destroy.handle = bo->handle;
	drmIoctl(fd, DRM_IOCTL_MODE_DESTROY_DUMB, &destroy);
}

int main(int argc, char **argv)
{
	int fd;
	drmModeConnector *conn;
	drmModeRes *res = NULL;
	drmModePlaneRes *plane_res;
	uint32_t conn_id;
	uint32_t crtc_id;
	uint32_t plane_id;
	int ret = 0;

	printf("ut enter modeprint\n");
	if(argc<2)
	{
		printf("usage ./modeprint_static_arm64 [dri card path]  example ./modeprint_static_arm64 /dev/dri/card1\n");
		exit(-1);
	}
	fd = open(argv[1], O_RDWR | O_CLOEXEC);
	if(fd<0)
	{
		perror("fd open failed:\n");
		exit(-1);
	}
	res = drmModeGetResources(fd);
	if(res == NULL)
	{
		printf("ut get res failed\n");
		exit(-1);
	}
	crtc_id = res->crtcs[0];
	conn_id = res->connectors[0];

	printf("ut crtc_id %d conn_id %d\n",crtc_id,conn_id);

	drmSetClientCap(fd, DRM_CLIENT_CAP_UNIVERSAL_PLANES, 1);
	plane_res = drmModeGetPlaneResources(fd);
	plane_id = plane_res->planes[0];

	conn = drmModeGetConnector(fd, conn_id);
	buf.width = conn->modes[0].hdisplay;
	buf.height = conn->modes[0].vdisplay;

	printf("ut buf.width %d buf.height %d\n",buf.width,buf.height);
	modeset_create_fb(fd, &buf);

	drmModeSetCrtc(fd, crtc_id, buf.fb_id,
			0, 0, &conn_id, 1, &conn->modes[0]);

	getchar();

	printf("ut ret %d\n",ret);
	/* crop the rect from framebuffer(100, 150) to crtc(50, 50) */
	ret = drmModeSetPlane(fd, plane_id, crtc_id, buf.fb_id, 0,
			50, 50, 320, 320,
			100 << 16, 150 << 16, 320 << 16, 320 << 16);
	printf("ut ret %d\n",ret);

	getchar();
	
	printf("ut step 1\n");
	modeset_destroy_fb(fd, &buf);

	drmModeFreeConnector(conn);
	drmModeFreePlaneResources(plane_res);
	drmModeFreeResources(res);

	close(fd);

	return 0;
}


