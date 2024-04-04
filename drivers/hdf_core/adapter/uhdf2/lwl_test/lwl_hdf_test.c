#include "devmgr_service.h"
#include "devmgr_service_full.h"
#include "devmgr_uevent.h"
#include "hdf_base.h"
#include "hdf_log.h"

#include "osal_mem.h"
#include "hdf_io_service_if.h"

#define HDF_LOG_TAG lwl_hdf_test

struct DevHandle {
    void *object;
};


struct DevHandle* TestServiceBind(void)
{
    struct DevHandle *handle = NULL;
    char *serviceName = "new_test";
	int ret;

	HDF_LOGE("Failed to OsalMemCalloc handle");
    handle = (struct DevHandle *)OsalMemCalloc(sizeof(struct DevHandle));
    if (handle == NULL) {
        HDF_LOGE("Failed to OsalMemCalloc handle");
        return NULL;
    }
    struct HdfIoService *service = HdfIoServiceBind(serviceName);

    if (service == NULL) {
        HDF_LOGE("Failed to get service %s", serviceName);
        OsalMemFree(handle);
        OsalMemFree(serviceName);
        return NULL;
    }
    handle->object = service;

    struct HdfSBuf *sBuf = HdfSbufObtainDefaultSize();
    if (sBuf == NULL) {
        HDF_LOGE("Failed to obtain sBuf");
        /* return HDF_FAILURE; */
		return NULL;
    }


    service = (struct HdfIoService *)handle->object;
    ret = service->dispatcher->Dispatch(&service->object, 1, sBuf, NULL);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("Failed to send service call");
    }

	return handle;
}

int main()
{
	/* int status = HDF_FAILURE; */
    /* struct IDevmgrService* instance = DevmgrServiceGetInstance(); */
    /* HDF_LOGE("LWL start hdf device manager"); */
	/* printf("11---------\n"); */
    /* if (instance == NULL) { */
        /* HDF_LOGE("Getting DevmgrService instance failed"); */
        /* return status; */
    /* } */

    /* if (instance->StartService != NULL) { */
        /* status = instance->StartService(instance); */
    /* } */
    HDF_LOGI("LWL start hdf device manager");
	TestServiceBind();
	return 0;
}

