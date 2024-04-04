/*************************************************************************
	> File Name: new_test.c
	> Author: Arctan
	> Created Time: 2024年01月22日 星期一 18时24分43秒
 ************************************************************************/

#include "hdf_base.h"
#include "hdf_device_desc.h"
#include "hdf_log.h"
#include "osal_mem.h"

#define HDF_LOG_TAG             new_test



static int32_t HdfNewTestDriverOpen(struct HdfDeviceIoClient *client)
{
	static int usecount = 0;

    HDF_LOGI("%s:newtest usecount=%d", __func__, usecount++);
	return HDF_SUCCESS;
}

static int32_t HdfNewTestIoServiceDispatch(struct HdfDeviceIoClient *client, int id, 
									struct HdfSBuf *data, struct HdfSBuf *reply)
{
	static int dispatch = 0;
    HDF_LOGI("%s:newtest dispatch=%d", __func__, dispatch++);
	return HDF_SUCCESS;
}
static void HdfNewTestDriverClose(struct HdfDeviceIoClient *client)
{
	static int closecount = 0;
    HDF_LOGI("%s:newtest closecount=%d", __func__, closecount++);

}

static int HdfNewTestDispatchInit(struct HdfDeviceObject *device)
{
	static struct IDeviceIoService NewTestService = {
        .Open = HdfNewTestDriverOpen,
        .Dispatch = HdfNewTestIoServiceDispatch,
        .Release = HdfNewTestDriverClose,
    };
    device->service = &NewTestService;
	return HDF_SUCCESS;
}

static int32_t HdfNewTestInit(struct HdfDeviceObject *device)
{
    HDF_LOGE("%s: LWL entry", __func__);
    /* PlatformDeviceSetHdfDev(&cntlr->device, device); */
    return HDF_SUCCESS;
}
static void HdfNewTestRelease(struct HdfDeviceObject *device)
{
    HDF_LOGE("%s: LWL  entry", __func__);
    if (device != NULL && device->service != NULL) {
        OsalMemFree(device->service);
    }
}
static int32_t HdfNewTestBind(struct HdfDeviceObject *device)
{

    struct IDeviceIoService *service = NULL;

    HDF_LOGE("%s: LWL--  entry", __func__);
    if (device == NULL) {
        return HDF_ERR_INVALID_OBJECT;
    }
	HdfNewTestDispatchInit(device);
    return HDF_SUCCESS;

}

static struct HdfDriverEntry g_hdfnewtest = {
    .moduleVersion = 1,
    .moduleName = "HDF_PLATFORM_NEW_TEST",
    .Bind = HdfNewTestBind,
    .Init = HdfNewTestInit,
    .Release = HdfNewTestRelease,
};

struct HdfDriverEntry *NewTestGetEntry(void)
{
    return &g_hdfnewtest;
}
HDF_INIT(g_hdfnewtest);
