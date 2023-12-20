/*
 * Tencent is pleased to support the open source community by making TKEStack
 * available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

//
// Created by thomas on 18-4-16.
//
#include <pthread.h>

#include "include/hijack.h"
#include "include/nvml-helper.h"

extern entry_t cuda_library_entry[];
extern entry_t nvml_library_entry[];
extern resource_data_t g_vcuda_config;
extern char pid_path[];

extern nvmlReturn_t nvmlInitWithFlags(unsigned int flags) {
  load_necessary_data();

  return NVML_ENTRY_CALL(nvml_library_entry, nvmlInitWithFlags, flags);
}

nvmlReturn_t nvmlInit_v2(void) {
  load_necessary_data();

  return NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2);
}

nvmlReturn_t nvmlInit(void) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlInit);
}

nvmlReturn_t nvmlShutdown(void) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlShutdown);
}

const char *nvmlErrorString(nvmlReturn_t result) {
  const char *(*_entry)(nvmlReturn_t) =
      NVML_FIND_ENTRY(nvml_library_entry, nvmlErrorString);

  return _entry(result);
}

nvmlReturn_t nvmlDeviceGetHandleByIndex_v2(unsigned int index,
                                           nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex_v2,
                         index, device);
}

nvmlReturn_t nvmlDeviceGetHandleByIndex(unsigned int index,
                                        nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex, index,
                         device);
}

nvmlReturn_t nvmlDeviceGetComputeRunningProcesses(nvmlDevice_t device,
                                                  unsigned int *infoCount,
                                                  nvmlProcessInfo_t *infos) {
  // LOGGER(5, "Call Rewrite Function: %s\n", "nvmlDeviceGetComputeRunningProcesses");
  // nvmlReturn_t ret;
  // ret = NVML_ENTRY_CALL(nvml_library_entry,
  //                        nvmlDeviceGetComputeRunningProcesses, device,
  //                        infoCount, infos);
  // if (g_vcuda_config.enable && ret == NVML_SUCCESS) {
  //     atomic_action(pid_path, load_pids_table, NULL);
  //     search_on_pids_table(infoCount, infos);
  // }
  // return ret; 
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetComputeRunningProcesses, device,
                         infoCount, infos);
}

nvmlReturn_t nvmlDeviceGetPciInfo_v3(nvmlDevice_t device, nvmlPciInfo_t *pci) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo_v3, device,
                         pci);
}

nvmlReturn_t nvmlDeviceGetPciInfo_v2(nvmlDevice_t device, nvmlPciInfo_t *pci) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo_v2, device,
                         pci);
}

nvmlReturn_t nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t *pci) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo, device, pci);
}

nvmlReturn_t nvmlDeviceGetProcessUtilization(
    nvmlDevice_t device, nvmlProcessUtilizationSample_t *utilization,
    unsigned int *processSamplesCount, unsigned long long lastSeenTimeStamp) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetProcessUtilization,
                         device, utilization, processSamplesCount,
                         lastSeenTimeStamp);
}

nvmlReturn_t nvmlDeviceGetCount_v2(unsigned int *deviceCount) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount_v2,
                         deviceCount);
}

nvmlReturn_t nvmlDeviceGetCount(unsigned int *deviceCount) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount, deviceCount);
}

nvmlReturn_t nvmlDeviceClearAccountingPids(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearAccountingPids,
                         device);
}

nvmlReturn_t nvmlDeviceClearCpuAffinity(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearCpuAffinity,
                         device);
}

nvmlReturn_t nvmlDeviceClearEccErrorCounts(nvmlDevice_t device,
                                           nvmlEccCounterType_t counterType) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearEccErrorCounts,
                         device, counterType);
}

nvmlReturn_t nvmlDeviceDiscoverGpus(nvmlPciInfo_t *pciInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceDiscoverGpus, pciInfo);
}

nvmlReturn_t
nvmlDeviceFreezeNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link,
                                         unsigned int counter,
                                         nvmlEnableState_t freeze) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceFreezeNvLinkUtilizationCounter, device, link,
                         counter, freeze);
}

nvmlReturn_t nvmlDeviceGetAccountingBufferSize(nvmlDevice_t device,
                                               unsigned int *bufferSize) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingBufferSize,
                         device, bufferSize);
}

nvmlReturn_t nvmlDeviceGetAccountingMode(nvmlDevice_t device,
                                         nvmlEnableState_t *mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingMode,
                         device, mode);
}

nvmlReturn_t nvmlDeviceGetAccountingPids(nvmlDevice_t device,
                                         unsigned int *count,
                                         unsigned int *pids) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingPids,
                         device, count, pids);
}

nvmlReturn_t nvmlDeviceGetAccountingStats(nvmlDevice_t device, unsigned int pid,
                                          nvmlAccountingStats_t *stats) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingStats,
                         device, pid, stats);
}

nvmlReturn_t nvmlDeviceGetActiveVgpus(nvmlDevice_t device,
                                      unsigned int *vgpuCount,
                                      nvmlVgpuInstance_t *vgpuInstances) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetActiveVgpus, device,
                         vgpuCount, vgpuInstances);
}

nvmlReturn_t nvmlDeviceGetAPIRestriction(nvmlDevice_t device,
                                         nvmlRestrictedAPI_t apiType,
                                         nvmlEnableState_t *isRestricted) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAPIRestriction,
                         device, apiType, isRestricted);
}

nvmlReturn_t nvmlDeviceGetApplicationsClock(nvmlDevice_t device,
                                            nvmlClockType_t clockType,
                                            unsigned int *clockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetApplicationsClock,
                         device, clockType, clockMHz);
}

nvmlReturn_t
nvmlDeviceGetAutoBoostedClocksEnabled(nvmlDevice_t device,
                                      nvmlEnableState_t *isEnabled,
                                      nvmlEnableState_t *defaultIsEnabled) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetAutoBoostedClocksEnabled, device,
                         isEnabled, defaultIsEnabled);
}

nvmlReturn_t nvmlDeviceGetBAR1MemoryInfo(nvmlDevice_t device,
                                         nvmlBAR1Memory_t *bar1Memory) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBAR1MemoryInfo,
                         device, bar1Memory);
}

nvmlReturn_t nvmlDeviceGetBoardId(nvmlDevice_t device, unsigned int *boardId) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBoardId, device,
                         boardId);
}

nvmlReturn_t nvmlDeviceGetBoardPartNumber(nvmlDevice_t device, char *partNumber,
                                          unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBoardPartNumber,
                         device, partNumber, length);
}

nvmlReturn_t nvmlDeviceGetBrand(nvmlDevice_t device, nvmlBrandType_t *type) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBrand, device, type);
}

nvmlReturn_t
nvmlDeviceGetBridgeChipInfo(nvmlDevice_t device,
                            nvmlBridgeChipHierarchy_t *bridgeHierarchy) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBridgeChipInfo,
                         device, bridgeHierarchy);
}

nvmlReturn_t nvmlDeviceGetClock(nvmlDevice_t device, nvmlClockType_t clockType,
                                nvmlClockId_t clockId, unsigned int *clockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClock, device,
                         clockType, clockId, clockMHz);
}

nvmlReturn_t nvmlDeviceGetClockInfo(nvmlDevice_t device, nvmlClockType_t type,
                                    unsigned int *clock) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClockInfo, device,
                         type, clock);
}

nvmlReturn_t nvmlDeviceGetComputeMode(nvmlDevice_t device,
                                      nvmlComputeMode_t *mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeMode, device,
                         mode);
}

nvmlReturn_t nvmlDeviceGetCpuAffinity(nvmlDevice_t device,
                                      unsigned int cpuSetSize,
                                      unsigned long *cpuSet) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCpuAffinity, device,
                         cpuSetSize, cpuSet);
}

nvmlReturn_t nvmlDeviceGetCreatableVgpus(nvmlDevice_t device,
                                         unsigned int *vgpuCount,
                                         nvmlVgpuTypeId_t *vgpuTypeIds) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCreatableVgpus,
                         device, vgpuCount, vgpuTypeIds);
}

nvmlReturn_t nvmlDeviceGetCudaComputeCapability(nvmlDevice_t device, int *major,
                                                int *minor) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCudaComputeCapability,
                         device, major, minor);
}

nvmlReturn_t nvmlDeviceGetCurrentClocksThrottleReasons(
    nvmlDevice_t device, unsigned long long *clocksThrottleReasons) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetCurrentClocksThrottleReasons, device,
                         clocksThrottleReasons);
}

nvmlReturn_t nvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device,
                                                 unsigned int *currLinkGen) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetCurrPcieLinkGeneration, device,
                         currLinkGen);
}

nvmlReturn_t nvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device,
                                            unsigned int *currLinkWidth) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrPcieLinkWidth,
                         device, currLinkWidth);
}

nvmlReturn_t nvmlDeviceGetDecoderUtilization(nvmlDevice_t device,
                                             unsigned int *utilization,
                                             unsigned int *samplingPeriodUs) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDecoderUtilization,
                         device, utilization, samplingPeriodUs);
}

nvmlReturn_t nvmlDeviceGetDefaultApplicationsClock(nvmlDevice_t device,
                                                   nvmlClockType_t clockType,
                                                   unsigned int *clockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetDefaultApplicationsClock, device,
                         clockType, clockMHz);
}

nvmlReturn_t nvmlDeviceGetDetailedEccErrors(nvmlDevice_t device,
                                            nvmlMemoryErrorType_t errorType,
                                            nvmlEccCounterType_t counterType,
                                            nvmlEccErrorCounts_t *eccCounts) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDetailedEccErrors,
                         device, errorType, counterType, eccCounts);
}

nvmlReturn_t nvmlDeviceGetDisplayActive(nvmlDevice_t device,
                                        nvmlEnableState_t *isActive) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDisplayActive, device,
                         isActive);
}

nvmlReturn_t nvmlDeviceGetDisplayMode(nvmlDevice_t device,
                                      nvmlEnableState_t *display) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDisplayMode, device,
                         display);
}

nvmlReturn_t nvmlDeviceGetDriverModel(nvmlDevice_t device,
                                      nvmlDriverModel_t *current,
                                      nvmlDriverModel_t *pending) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDriverModel, device,
                         current, pending);
}

nvmlReturn_t nvmlDeviceGetEccMode(nvmlDevice_t device,
                                  nvmlEnableState_t *current,
                                  nvmlEnableState_t *pending) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEccMode, device,
                         current, pending);
}

nvmlReturn_t nvmlDeviceSetEccMode(nvmlDevice_t device, nvmlEnableState_t ecc) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetEccMode, device, ecc);
}

nvmlReturn_t nvmlDeviceGetEncoderCapacity(nvmlDevice_t device,
                                          nvmlEncoderType_t encoderQueryType,
                                          unsigned int *encoderCapacity) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderCapacity,
                         device, encoderQueryType, encoderCapacity);
}

nvmlReturn_t
nvmlDeviceGetEncoderSessions(nvmlDevice_t device, unsigned int *sessionCount,
                             nvmlEncoderSessionInfo_t *sessionInfos) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderSessions,
                         device, sessionCount, sessionInfos);
}

nvmlReturn_t nvmlDeviceGetEncoderStats(nvmlDevice_t device,
                                       unsigned int *sessionCount,
                                       unsigned int *averageFps,
                                       unsigned int *averageLatency) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderStats, device,
                         sessionCount, averageFps, averageLatency);
}

nvmlReturn_t nvmlDeviceGetEncoderUtilization(nvmlDevice_t device,
                                             unsigned int *utilization,
                                             unsigned int *samplingPeriodUs) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderUtilization,
                         device, utilization, samplingPeriodUs);
}

nvmlReturn_t nvmlDeviceGetEnforcedPowerLimit(nvmlDevice_t device,
                                             unsigned int *limit) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEnforcedPowerLimit,
                         device, limit);
}

nvmlReturn_t nvmlDeviceGetFanSpeed(nvmlDevice_t device, unsigned int *speed) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanSpeed, device,
                         speed);
}

nvmlReturn_t nvmlDeviceGetFanSpeed_v2(nvmlDevice_t device,
                                      unsigned int *speed) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanSpeed_v2, device,
                         speed);
}

nvmlReturn_t nvmlDeviceGetFieldValues(nvmlDevice_t device, int valuesCount,
                                      nvmlFieldValue_t *values) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFieldValues, device,
                         valuesCount, values);
}

nvmlReturn_t nvmlDeviceGetGpuOperationMode(nvmlDevice_t device,
                                           nvmlGpuOperationMode_t *current,
                                           nvmlGpuOperationMode_t *pending) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuOperationMode,
                         device, current, pending);
}

nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses(nvmlDevice_t device,
                                                   unsigned int *infoCount,
                                                   nvmlProcessInfo_t *infos) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGraphicsRunningProcesses, device,
                         infoCount, infos);
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v4(
    nvmlDevice_t device,
    nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGridLicensableFeatures_v4, device,
                         pGridLicensableFeatures);
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures(
    nvmlDevice_t device,
    nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGridLicensableFeatures, device,
                         pGridLicensableFeatures);
}

nvmlReturn_t nvmlDeviceGetHandleByPciBusId_v2(const char *pciBusId,
                                              nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByPciBusId_v2,
                         pciBusId, device);
}

nvmlReturn_t nvmlDeviceGetHandleByPciBusId(const char *pciBusId,
                                           nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByPciBusId,
                         pciBusId, device);
}

nvmlReturn_t nvmlDeviceGetHandleBySerial(const char *serial,
                                         nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleBySerial,
                         serial, device);
}

nvmlReturn_t nvmlDeviceGetHandleByUUID(const char *uuid, nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByUUID, uuid,
                         device);
}

nvmlReturn_t nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int *index) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIndex, device, index);
}

nvmlReturn_t nvmlDeviceGetInforomConfigurationChecksum(nvmlDevice_t device,
                                                       unsigned int *checksum) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetInforomConfigurationChecksum, device,
                         checksum);
}

nvmlReturn_t nvmlDeviceGetInforomImageVersion(nvmlDevice_t device,
                                              char *version,
                                              unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomImageVersion,
                         device, version, length);
}

nvmlReturn_t nvmlDeviceGetInforomVersion(nvmlDevice_t device,
                                         nvmlInforomObject_t object,
                                         char *version, unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomVersion,
                         device, object, version, length);
}

nvmlReturn_t nvmlDeviceGetMaxClockInfo(nvmlDevice_t device,
                                       nvmlClockType_t type,
                                       unsigned int *clock) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxClockInfo, device,
                         type, clock);
}

nvmlReturn_t nvmlDeviceGetMaxCustomerBoostClock(nvmlDevice_t device,
                                                nvmlClockType_t clockType,
                                                unsigned int *clockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxCustomerBoostClock,
                         device, clockType, clockMHz);
}

nvmlReturn_t nvmlDeviceGetMaxPcieLinkGeneration(nvmlDevice_t device,
                                                unsigned int *maxLinkGen) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxPcieLinkGeneration,
                         device, maxLinkGen);
}

nvmlReturn_t nvmlDeviceGetMaxPcieLinkWidth(nvmlDevice_t device,
                                           unsigned int *maxLinkWidth) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxPcieLinkWidth,
                         device, maxLinkWidth);
}

nvmlReturn_t nvmlDeviceGetMemoryErrorCounter(nvmlDevice_t device,
                                             nvmlMemoryErrorType_t errorType,
                                             nvmlEccCounterType_t counterType,
                                             nvmlMemoryLocation_t locationType,
                                             unsigned long long *count) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryErrorCounter,
                         device, errorType, counterType, locationType, count);
}

// TODO 再此拦截要显示的设备内存
nvmlReturn_t nvmlDeviceGetMemoryInfo(nvmlDevice_t device,
                                     nvmlMemory_t *memory) {
  nvmlReturn_t ret;
  ret = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryInfo, device,
                         memory);
    size_t used = 0;
    if (g_vcuda_config.enable && ret == NVML_SUCCESS) {
      atomic_action(pid_path, get_used_gpu_memory, (void *)&used);
      // 最大可用显存限制为 vcuda 分配时的大小
      memory->total = g_vcuda_config.gpu_memory;
      //memory->used = used + memory->reserved;
      memory->used = used;
      memory->free = memory->used > g_vcuda_config.gpu_memory ? 0 : g_vcuda_config.gpu_memory - memory->used;
    }
  return ret;
}

// TODO 再此拦截要显示的设备内存
nvmlReturn_t nvmlDeviceGetMemoryInfo_v2(nvmlDevice_t device, 
                                        nvmlMemory_v2_t *memory) {
    nvmlReturn_t ret;
    ret = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryInfo_v2, device, 
                          memory);
    size_t used = 0;
    if (g_vcuda_config.enable && ret == NVML_SUCCESS) {
      atomic_action(pid_path, get_used_gpu_memory, (void *)&used);
      // 最大可用显存限制为 vcuda 分配时的大小
      memory->total = g_vcuda_config.gpu_memory;
      memory->used = used; // v2 版本接口used和reserved是分开计算的
      //memory->free = (used + memory->reserved) > g_vcuda_config.gpu_memory ? 0 : g_vcuda_config.gpu_memory - used - memory->reserved;
      memory->free = used > g_vcuda_config.gpu_memory ? 0 : g_vcuda_config.gpu_memory - used;
    }
    return ret; 
}

nvmlReturn_t nvmlDeviceGetMinorNumber(nvmlDevice_t device,
                                      unsigned int *minorNumber) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMinorNumber, device,
                         minorNumber);
}

// Guessed function proto type
nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v2(nvmlDevice_t device,
                                                        unsigned int *infoCount,
                                                        void *infos) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetMPSComputeRunningProcesses_v2, device,
                         infoCount, infos);
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses(nvmlDevice_t device,
                                                     unsigned int *infoCount,
                                                     void *infos) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetMPSComputeRunningProcesses, device,
                         infoCount, infos);
}

nvmlReturn_t nvmlDeviceGetMultiGpuBoard(nvmlDevice_t device,
                                        unsigned int *multiGpuBool) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMultiGpuBoard, device,
                         multiGpuBool);
}

nvmlReturn_t nvmlDeviceGetName(nvmlDevice_t device, char *name,
                               unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetName, device, name,
                         length);
}

nvmlReturn_t nvmlDeviceGetNvLinkCapability(nvmlDevice_t device,
                                           unsigned int link,
                                           nvmlNvLinkCapability_t capability,
                                           unsigned int *capResult) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkCapability,
                         device, link, capability, capResult);
}

nvmlReturn_t nvmlDeviceGetNvLinkErrorCounter(nvmlDevice_t device,
                                             unsigned int link,
                                             nvmlNvLinkErrorCounter_t counter,
                                             unsigned long long *counterValue) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkErrorCounter,
                         device, link, counter, counterValue);
}

nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo_v2(nvmlDevice_t device,
                                                 unsigned int link,
                                                 nvmlPciInfo_t *pci) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetNvLinkRemotePciInfo_v2, device, link,
                         pci);
}

nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo(nvmlDevice_t device,
                                              unsigned int link,
                                              nvmlPciInfo_t *pci) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemotePciInfo,
                         device, link, pci);
}

nvmlReturn_t nvmlDeviceGetNvLinkState(nvmlDevice_t device, unsigned int link,
                                      nvmlEnableState_t *isActive) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkState, device,
                         link, isActive);
}

nvmlReturn_t
nvmlDeviceGetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link,
                                      unsigned int counter,
                                      nvmlNvLinkUtilizationControl_t *control) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetNvLinkUtilizationControl, device, link,
                         counter, control);
}

nvmlReturn_t nvmlDeviceGetNvLinkUtilizationCounter(
    nvmlDevice_t device, unsigned int link, unsigned int counter,
    unsigned long long *rxcounter, unsigned long long *txcounter) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetNvLinkUtilizationCounter, device, link,
                         counter, rxcounter, txcounter);
}

nvmlReturn_t nvmlDeviceGetNvLinkVersion(nvmlDevice_t device, unsigned int link,
                                        unsigned int *version) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkVersion, device,
                         link, version);
}

nvmlReturn_t nvmlDeviceGetP2PStatus(nvmlDevice_t device1, nvmlDevice_t device2,
                                    nvmlGpuP2PCapsIndex_t p2pIndex,
                                    nvmlGpuP2PStatus_t *p2pStatus) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetP2PStatus, device1,
                         device2, p2pIndex, p2pStatus);
}

nvmlReturn_t nvmlDeviceGetPcieReplayCounter(nvmlDevice_t device,
                                            unsigned int *value) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieReplayCounter,
                         device, value);
}

nvmlReturn_t nvmlDeviceGetPcieThroughput(nvmlDevice_t device,
                                         nvmlPcieUtilCounter_t counter,
                                         unsigned int *value) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieThroughput,
                         device, counter, value);
}

nvmlReturn_t nvmlDeviceGetPerformanceState(nvmlDevice_t device,
                                           nvmlPstates_t *pState) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPerformanceState,
                         device, pState);
}

nvmlReturn_t nvmlDeviceGetPersistenceMode(nvmlDevice_t device,
                                          nvmlEnableState_t *mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPersistenceMode,
                         device, mode);
}

nvmlReturn_t
nvmlDeviceGetPowerManagementDefaultLimit(nvmlDevice_t device,
                                         unsigned int *defaultLimit) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetPowerManagementDefaultLimit, device,
                         defaultLimit);
}

nvmlReturn_t nvmlDeviceGetPowerManagementLimit(nvmlDevice_t device,
                                               unsigned int *limit) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementLimit,
                         device, limit);
}

nvmlReturn_t nvmlDeviceGetPowerManagementLimitConstraints(
    nvmlDevice_t device, unsigned int *minLimit, unsigned int *maxLimit) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetPowerManagementLimitConstraints, device,
                         minLimit, maxLimit);
}

nvmlReturn_t nvmlDeviceGetPowerManagementMode(nvmlDevice_t device,
                                              nvmlEnableState_t *mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementMode,
                         device, mode);
}

nvmlReturn_t nvmlDeviceGetPowerState(nvmlDevice_t device,
                                     nvmlPstates_t *pState) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerState, device,
                         pState);
}

nvmlReturn_t nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int *power) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerUsage, device,
                         power);
}

nvmlReturn_t nvmlDeviceGetRetiredPages(nvmlDevice_t device,
                                       nvmlPageRetirementCause_t cause,
                                       unsigned int *pageCount,
                                       unsigned long long *addresses) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPages, device,
                         cause, pageCount, addresses);
}

nvmlReturn_t
nvmlDeviceGetRetiredPagesPendingStatus(nvmlDevice_t device,
                                       nvmlEnableState_t *isPending) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetRetiredPagesPendingStatus, device,
                         isPending);
}

nvmlReturn_t nvmlDeviceGetSamples(nvmlDevice_t device, nvmlSamplingType_t type,
                                  unsigned long long lastSeenTimeStamp,
                                  nvmlValueType_t *sampleValType,
                                  unsigned int *sampleCount,
                                  nvmlSample_t *samples) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSamples, device, type,
                         lastSeenTimeStamp, sampleValType, sampleCount,
                         samples);
}

nvmlReturn_t nvmlDeviceGetSerial(nvmlDevice_t device, char *serial,
                                 unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSerial, device,
                         serial, length);
}

nvmlReturn_t nvmlDeviceGetSupportedClocksThrottleReasons(
    nvmlDevice_t device, unsigned long long *supportedClocksThrottleReasons) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetSupportedClocksThrottleReasons, device,
                         supportedClocksThrottleReasons);
}

nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device,
                                              unsigned long long *eventTypes) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedEventTypes,
                         device, eventTypes);
}

nvmlReturn_t nvmlDeviceGetSupportedGraphicsClocks(nvmlDevice_t device,
                                                  unsigned int memoryClockMHz,
                                                  unsigned int *count,
                                                  unsigned int *clocksMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetSupportedGraphicsClocks, device,
                         memoryClockMHz, count, clocksMHz);
}

nvmlReturn_t nvmlDeviceGetSupportedMemoryClocks(nvmlDevice_t device,
                                                unsigned int *count,
                                                unsigned int *clocksMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedMemoryClocks,
                         device, count, clocksMHz);
}

nvmlReturn_t nvmlDeviceGetSupportedVgpus(nvmlDevice_t device,
                                         unsigned int *vgpuCount,
                                         nvmlVgpuTypeId_t *vgpuTypeIds) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedVgpus,
                         device, vgpuCount, vgpuTypeIds);
}

nvmlReturn_t nvmlDeviceGetTemperature(nvmlDevice_t device,
                                      nvmlTemperatureSensors_t sensorType,
                                      unsigned int *temp) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTemperature, device,
                         sensorType, temp);
}

nvmlReturn_t
nvmlDeviceGetTemperatureThreshold(nvmlDevice_t device,
                                  nvmlTemperatureThresholds_t thresholdType,
                                  unsigned int *temp) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTemperatureThreshold,
                         device, thresholdType, temp);
}

nvmlReturn_t
nvmlDeviceGetTopologyCommonAncestor(nvmlDevice_t device1, nvmlDevice_t device2,
                                    nvmlGpuTopologyLevel_t *pathInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetTopologyCommonAncestor, device1, device2,
                         pathInfo);
}

nvmlReturn_t nvmlDeviceGetTopologyNearestGpus(nvmlDevice_t device,
                                              nvmlGpuTopologyLevel_t level,
                                              unsigned int *count,
                                              nvmlDevice_t *deviceArray) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTopologyNearestGpus,
                         device, level, count, deviceArray);
}

nvmlReturn_t nvmlDeviceGetTotalEccErrors(nvmlDevice_t device,
                                         nvmlMemoryErrorType_t errorType,
                                         nvmlEccCounterType_t counterType,
                                         unsigned long long *eccCounts) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTotalEccErrors,
                         device, errorType, counterType, eccCounts);
}

nvmlReturn_t nvmlDeviceGetTotalEnergyConsumption(nvmlDevice_t device,
                                                 unsigned long long *energy) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetTotalEnergyConsumption, device, energy);
}

nvmlReturn_t nvmlDeviceGetUtilizationRates(nvmlDevice_t device,
                                           nvmlUtilization_t *utilization) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUtilizationRates,
                         device, utilization);
}

nvmlReturn_t nvmlDeviceGetUUID(nvmlDevice_t device, char *uuid,
                               unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUUID, device, uuid,
                         length);
}

nvmlReturn_t nvmlDeviceGetVbiosVersion(nvmlDevice_t device, char *version,
                                       unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVbiosVersion, device,
                         version, length);
}

nvmlReturn_t nvmlDeviceGetVgpuMetadata(nvmlDevice_t device,
                                       nvmlVgpuPgpuMetadata_t *pgpuMetadata,
                                       unsigned int *bufferSize) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuMetadata, device,
                         pgpuMetadata, bufferSize);
}

nvmlReturn_t nvmlDeviceGetVgpuProcessUtilization(
    nvmlDevice_t device, unsigned long long lastSeenTimeStamp,
    unsigned int *vgpuProcessSamplesCount,
    nvmlVgpuProcessUtilizationSample_t *utilizationSamples) {
  return NVML_ENTRY_CALL(
      nvml_library_entry, nvmlDeviceGetVgpuProcessUtilization, device,
      lastSeenTimeStamp, vgpuProcessSamplesCount, utilizationSamples);
}

nvmlReturn_t nvmlDeviceGetVgpuUtilization(
    nvmlDevice_t device, unsigned long long lastSeenTimeStamp,
    nvmlValueType_t *sampleValType, unsigned int *vgpuInstanceSamplesCount,
    nvmlVgpuInstanceUtilizationSample_t *utilizationSamples) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuUtilization,
                         device, lastSeenTimeStamp, sampleValType,
                         vgpuInstanceSamplesCount, utilizationSamples);
}

nvmlReturn_t nvmlDeviceGetViolationStatus(nvmlDevice_t device,
                                          nvmlPerfPolicyType_t perfPolicyType,
                                          nvmlViolationTime_t *violTime) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetViolationStatus,
                         device, perfPolicyType, violTime);
}

nvmlReturn_t
nvmlDeviceGetVirtualizationMode(nvmlDevice_t device,
                                nvmlGpuVirtualizationMode_t *pVirtualMode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVirtualizationMode,
                         device, pVirtualMode);
}

nvmlReturn_t nvmlDeviceModifyDrainState(nvmlPciInfo_t *pciInfo,
                                        nvmlEnableState_t newState) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceModifyDrainState,
                         pciInfo, newState);
}

nvmlReturn_t nvmlDeviceOnSameBoard(nvmlDevice_t device1, nvmlDevice_t device2,
                                   int *onSameBoard) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceOnSameBoard, device1,
                         device2, onSameBoard);
}

nvmlReturn_t nvmlDeviceQueryDrainState(nvmlPciInfo_t *pciInfo,
                                       nvmlEnableState_t *currentState) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceQueryDrainState, pciInfo,
                         currentState);
}

nvmlReturn_t nvmlDeviceRegisterEvents(nvmlDevice_t device,
                                      unsigned long long eventTypes,
                                      nvmlEventSet_t set) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRegisterEvents, device,
                         eventTypes, set);
}

nvmlReturn_t nvmlDeviceRemoveGpu_v2(nvmlPciInfo_t *pciInfo,
                                    nvmlDetachGpuState_t gpuState,
                                    nvmlPcieLinkState_t linkState) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRemoveGpu_v2, pciInfo,
                         gpuState, linkState);
}

nvmlReturn_t nvmlDeviceRemoveGpu(nvmlPciInfo_t *pciInfo,
                                 nvmlDetachGpuState_t gpuState,
                                 nvmlPcieLinkState_t linkState) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRemoveGpu, pciInfo,
                         gpuState, linkState);
}

nvmlReturn_t nvmlDeviceResetApplicationsClocks(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetApplicationsClocks,
                         device);
}

nvmlReturn_t nvmlDeviceResetNvLinkErrorCounters(nvmlDevice_t device,
                                                unsigned int link) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetNvLinkErrorCounters,
                         device, link);
}

nvmlReturn_t nvmlDeviceResetNvLinkUtilizationCounter(nvmlDevice_t device,
                                                     unsigned int link,
                                                     unsigned int counter) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceResetNvLinkUtilizationCounter, device, link,
                         counter);
}

nvmlReturn_t nvmlDeviceSetAccountingMode(nvmlDevice_t device,
                                         nvmlEnableState_t mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAccountingMode,
                         device, mode);
}

nvmlReturn_t nvmlDeviceSetAPIRestriction(nvmlDevice_t device,
                                         nvmlRestrictedAPI_t apiType,
                                         nvmlEnableState_t isRestricted) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAPIRestriction,
                         device, apiType, isRestricted);
}

nvmlReturn_t nvmlDeviceSetApplicationsClocks(nvmlDevice_t device,
                                             unsigned int memClockMHz,
                                             unsigned int graphicsClockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetApplicationsClocks,
                         device, memClockMHz, graphicsClockMHz);
}

nvmlReturn_t nvmlDeviceSetAutoBoostedClocksEnabled(nvmlDevice_t device,
                                                   nvmlEnableState_t enabled) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceSetAutoBoostedClocksEnabled, device,
                         enabled);
}

nvmlReturn_t nvmlDeviceSetComputeMode(nvmlDevice_t device,
                                      nvmlComputeMode_t mode) {
  if (g_vcuda_config.enable) {
    return NVML_ERROR_NOT_SUPPORTED;
  }

  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetComputeMode, device,
                         mode);
}

nvmlReturn_t nvmlDeviceSetCpuAffinity(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetCpuAffinity, device);
}

nvmlReturn_t nvmlDeviceSetDefaultAutoBoostedClocksEnabled(
    nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceSetDefaultAutoBoostedClocksEnabled, device,
                         enabled, flags);
}

nvmlReturn_t nvmlDeviceSetDriverModel(nvmlDevice_t device,
                                      nvmlDriverModel_t driverModel,
                                      unsigned int flags) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetDriverModel, device,
                         driverModel, flags);
}

nvmlReturn_t nvmlDeviceSetGpuOperationMode(nvmlDevice_t device,
                                           nvmlGpuOperationMode_t mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpuOperationMode,
                         device, mode);
}

nvmlReturn_t nvmlDeviceSetNvLinkUtilizationControl(
    nvmlDevice_t device, unsigned int link, unsigned int counter,
    nvmlNvLinkUtilizationControl_t *control, unsigned int reset) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceSetNvLinkUtilizationControl, device, link,
                         counter, control, reset);
}

nvmlReturn_t nvmlDeviceSetPersistenceMode(nvmlDevice_t device,
                                          nvmlEnableState_t mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPersistenceMode,
                         device, mode);
}

nvmlReturn_t nvmlDeviceSetPowerManagementLimit(nvmlDevice_t device,
                                               unsigned int limit) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPowerManagementLimit,
                         device, limit);
}

nvmlReturn_t
nvmlDeviceSetVirtualizationMode(nvmlDevice_t device,
                                nvmlGpuVirtualizationMode_t virtualMode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetVirtualizationMode,
                         device, virtualMode);
}

nvmlReturn_t nvmlDeviceValidateInforom(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceValidateInforom, device);
}

nvmlReturn_t nvmlEventSetCreate(nvmlEventSet_t *set) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetCreate, set);
}

nvmlReturn_t nvmlEventSetFree(nvmlEventSet_t set) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetFree, set);
}

nvmlReturn_t nvmlEventSetWait(nvmlEventSet_t set, nvmlEventData_t *data,
                              unsigned int timeoutms) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetWait, set, data,
                         timeoutms);
}

nvmlReturn_t
nvmlGetVgpuCompatibility(nvmlVgpuMetadata_t *vgpuMetadata,
                         nvmlVgpuPgpuMetadata_t *pgpuMetadata,
                         nvmlVgpuPgpuCompatibility_t *compatibilityInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuCompatibility,
                         vgpuMetadata, pgpuMetadata, compatibilityInfo);
}

nvmlReturn_t nvmlInternalGetExportTable(const void **ppExportTable,
                                        void *pExportTableId) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlInternalGetExportTable,
                         ppExportTable, pExportTableId);
}

nvmlReturn_t nvmlSystemGetCudaDriverVersion(int *cudaDriverVersion) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetCudaDriverVersion,
                         cudaDriverVersion);
}

nvmlReturn_t nvmlSystemGetCudaDriverVersion_v2(int *cudaDriverVersion) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetCudaDriverVersion_v2,
                         cudaDriverVersion);
}

nvmlReturn_t nvmlSystemGetDriverVersion(char *version, unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetDriverVersion,
                         version, length);
}

nvmlReturn_t nvmlSystemGetHicVersion(unsigned int *hwbcCount,
                                     nvmlHwbcEntry_t *hwbcEntries) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetHicVersion, hwbcCount,
                         hwbcEntries);
}

nvmlReturn_t nvmlSystemGetNVMLVersion(char *version, unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetNVMLVersion, version,
                         length);
}

nvmlReturn_t nvmlSystemGetProcessName(unsigned int pid, char *name,
                                      unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetProcessName, pid,
                         name, length);
}

nvmlReturn_t nvmlSystemGetTopologyGpuSet(unsigned int cpuNumber,
                                         unsigned int *count,
                                         nvmlDevice_t *deviceArray) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetTopologyGpuSet,
                         cpuNumber, count, deviceArray);
}

nvmlReturn_t nvmlUnitGetCount(unsigned int *unitCount) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetCount, unitCount);
}

nvmlReturn_t nvmlUnitGetDevices(nvmlUnit_t unit, unsigned int *deviceCount,
                                nvmlDevice_t *devices) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetDevices, unit,
                         deviceCount, devices);
}

nvmlReturn_t nvmlUnitGetFanSpeedInfo(nvmlUnit_t unit,
                                     nvmlUnitFanSpeeds_t *fanSpeeds) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetFanSpeedInfo, unit,
                         fanSpeeds);
}

nvmlReturn_t nvmlUnitGetHandleByIndex(unsigned int index, nvmlUnit_t *unit) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetHandleByIndex, index,
                         unit);
}

nvmlReturn_t nvmlUnitGetLedState(nvmlUnit_t unit, nvmlLedState_t *state) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetLedState, unit, state);
}

nvmlReturn_t nvmlUnitGetPsuInfo(nvmlUnit_t unit, nvmlPSUInfo_t *psu) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetPsuInfo, unit, psu);
}

nvmlReturn_t nvmlUnitGetTemperature(nvmlUnit_t unit, unsigned int type,
                                    unsigned int *temp) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetTemperature, unit, type,
                         temp);
}

nvmlReturn_t nvmlUnitGetUnitInfo(nvmlUnit_t unit, nvmlUnitInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetUnitInfo, unit, info);
}

nvmlReturn_t nvmlUnitSetLedState(nvmlUnit_t unit, nvmlLedColor_t color) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitSetLedState, unit, color);
}

nvmlReturn_t nvmlVgpuInstanceGetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance,
                                                unsigned int *encoderCapacity) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderCapacity,
                         vgpuInstance, encoderCapacity);
}

nvmlReturn_t
nvmlVgpuInstanceGetEncoderSessions(nvmlVgpuInstance_t vgpuInstance,
                                   unsigned int *sessionCount,
                                   nvmlEncoderSessionInfo_t *sessionInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderSessions,
                         vgpuInstance, sessionCount, sessionInfo);
}

nvmlReturn_t nvmlVgpuInstanceGetEncoderStats(nvmlVgpuInstance_t vgpuInstance,
                                             unsigned int *sessionCount,
                                             unsigned int *averageFps,
                                             unsigned int *averageLatency) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderStats,
                         vgpuInstance, sessionCount, averageFps,
                         averageLatency);
}

nvmlReturn_t nvmlVgpuInstanceGetFbUsage(nvmlVgpuInstance_t vgpuInstance,
                                        unsigned long long *fbUsage) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFbUsage,
                         vgpuInstance, fbUsage);
}

nvmlReturn_t nvmlVgpuInstanceGetFrameRateLimit(nvmlVgpuInstance_t vgpuInstance,
                                               unsigned int *frameRateLimit) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFrameRateLimit,
                         vgpuInstance, frameRateLimit);
}

nvmlReturn_t nvmlVgpuInstanceGetLicenseStatus(nvmlVgpuInstance_t vgpuInstance,
                                              unsigned int *licensed) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseStatus,
                         vgpuInstance, licensed);
}

nvmlReturn_t nvmlVgpuInstanceGetMetadata(nvmlVgpuInstance_t vgpuInstance,
                                         nvmlVgpuMetadata_t *vgpuMetadata,
                                         unsigned int *bufferSize) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetMetadata,
                         vgpuInstance, vgpuMetadata, bufferSize);
}

nvmlReturn_t nvmlVgpuInstanceGetType(nvmlVgpuInstance_t vgpuInstance,
                                     nvmlVgpuTypeId_t *vgpuTypeId) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetType,
                         vgpuInstance, vgpuTypeId);
}

nvmlReturn_t nvmlVgpuInstanceGetUUID(nvmlVgpuInstance_t vgpuInstance,
                                     char *uuid, unsigned int size) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetUUID,
                         vgpuInstance, uuid, size);
}

nvmlReturn_t nvmlVgpuInstanceGetVmDriverVersion(nvmlVgpuInstance_t vgpuInstance,
                                                char *version,
                                                unsigned int length) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetVmDriverVersion,
                         vgpuInstance, version, length);
}

nvmlReturn_t nvmlVgpuInstanceGetVmID(nvmlVgpuInstance_t vgpuInstance,
                                     char *vmId, unsigned int size,
                                     nvmlVgpuVmIdType_t *vmIdType) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetVmID,
                         vgpuInstance, vmId, size, vmIdType);
}

nvmlReturn_t nvmlVgpuInstanceSetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance,
                                                unsigned int encoderCapacity) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceSetEncoderCapacity,
                         vgpuInstance, encoderCapacity);
}

nvmlReturn_t nvmlVgpuTypeGetClass(nvmlVgpuTypeId_t vgpuTypeId,
                                  char *vgpuTypeClass, unsigned int *size) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetClass, vgpuTypeId,
                         vgpuTypeClass, size);
}

nvmlReturn_t nvmlVgpuTypeGetDeviceID(nvmlVgpuTypeId_t vgpuTypeId,
                                     unsigned long long *deviceID,
                                     unsigned long long *subsystemID) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetDeviceID,
                         vgpuTypeId, deviceID, subsystemID);
}

nvmlReturn_t nvmlVgpuTypeGetFramebufferSize(nvmlVgpuTypeId_t vgpuTypeId,
                                            unsigned long long *fbSize) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetFramebufferSize,
                         vgpuTypeId, fbSize);
}

nvmlReturn_t nvmlVgpuTypeGetFrameRateLimit(nvmlVgpuTypeId_t vgpuTypeId,
                                           unsigned int *frameRateLimit) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetFrameRateLimit,
                         vgpuTypeId, frameRateLimit);
}

nvmlReturn_t nvmlVgpuTypeGetLicense(nvmlVgpuTypeId_t vgpuTypeId,
                                    char *vgpuTypeLicenseString,
                                    unsigned int size) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetLicense, vgpuTypeId,
                         vgpuTypeLicenseString, size);
}

nvmlReturn_t nvmlVgpuTypeGetMaxInstances(nvmlDevice_t device,
                                         nvmlVgpuTypeId_t vgpuTypeId,
                                         unsigned int *vgpuInstanceCount) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetMaxInstances,
                         device, vgpuTypeId, vgpuInstanceCount);
}

nvmlReturn_t nvmlVgpuTypeGetName(nvmlVgpuTypeId_t vgpuTypeId,
                                 char *vgpuTypeName, unsigned int *size) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetName, vgpuTypeId,
                         vgpuTypeName, size);
}

nvmlReturn_t nvmlVgpuTypeGetNumDisplayHeads(nvmlVgpuTypeId_t vgpuTypeId,
                                            unsigned int *numDisplayHeads) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetNumDisplayHeads,
                         vgpuTypeId, numDisplayHeads);
}

nvmlReturn_t nvmlVgpuTypeGetResolution(nvmlVgpuTypeId_t vgpuTypeId,
                                       unsigned int displayIndex,
                                       unsigned int *xdim, unsigned int *ydim) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetResolution,
                         vgpuTypeId, displayIndex, xdim, ydim);
}

nvmlReturn_t nvmlDeviceGetFBCSessions(nvmlDevice_t device,
                                      unsigned int *sessionCount,
                                      nvmlFBCSessionInfo_t *sessionInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFBCSessions, device,
                         sessionCount, sessionInfo);
}

nvmlReturn_t nvmlDeviceGetFBCStats(nvmlDevice_t device,
                                   nvmlFBCStats_t *fbcStats) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFBCStats, device,
                         fbcStats);
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v2(
    nvmlDevice_t device,
    nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGridLicensableFeatures_v2, device,
                         pGridLicensableFeatures);
}

nvmlReturn_t nvmlDeviceGetRetiredPages_v2(nvmlDevice_t device,
                                          nvmlPageRetirementCause_t cause,
                                          unsigned int *pageCount,
                                          unsigned long long *addresses) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPages_v2,
                         device, cause, pageCount, addresses);
}

nvmlReturn_t nvmlDeviceResetGpuLockedClocks(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetGpuLockedClocks,
                         device);
}

nvmlReturn_t nvmlDeviceSetGpuLockedClocks(nvmlDevice_t device,
                                          unsigned int minGpuClockMHz,
                                          unsigned int maxGpuClockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpuLockedClocks,
                         device, minGpuClockMHz, maxGpuClockMHz);
}

nvmlReturn_t nvmlGetBlacklistDeviceCount(unsigned int *deviceCount) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetBlacklistDeviceCount,
                         deviceCount);
}

nvmlReturn_t
nvmlGetBlacklistDeviceInfoByIndex(unsigned int index,
                                  nvmlBlacklistDeviceInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetBlacklistDeviceInfoByIndex,
                         index, info);
}

nvmlReturn_t nvmlVgpuInstanceGetAccountingMode(nvmlVgpuInstance_t vgpuInstance,
                                               nvmlEnableState_t *mode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingMode,
                         vgpuInstance, mode);
}

nvmlReturn_t nvmlVgpuInstanceGetAccountingPids(nvmlVgpuInstance_t vgpuInstance,
                                               unsigned int *count,
                                               unsigned int *pids) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingPids,
                         vgpuInstance, count, pids);
}

nvmlReturn_t nvmlVgpuInstanceGetAccountingStats(nvmlVgpuInstance_t vgpuInstance,
                                                unsigned int pid,
                                                nvmlAccountingStats_t *stats) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingStats,
                         vgpuInstance, pid, stats);
}

nvmlReturn_t nvmlVgpuInstanceGetFBCSessions(nvmlVgpuInstance_t vgpuInstance,
                                            unsigned int *sessionCount,
                                            nvmlFBCSessionInfo_t *sessionInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFBCSessions,
                         vgpuInstance, sessionCount, sessionInfo);
}

nvmlReturn_t nvmlVgpuInstanceGetFBCStats(nvmlVgpuInstance_t vgpuInstance,
                                         nvmlFBCStats_t *fbcStats) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFBCStats,
                         vgpuInstance, fbcStats);
}

nvmlReturn_t
nvmlVgpuTypeGetMaxInstancesPerVm(nvmlVgpuTypeId_t vgpuTypeId,
                                 unsigned int *vgpuInstanceCountPerVm) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetMaxInstancesPerVm,
                         vgpuTypeId, vgpuInstanceCountPerVm);
}

nvmlReturn_t nvmlGetVgpuVersion(nvmlVgpuVersion_t *supported,
                                nvmlVgpuVersion_t *current) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuVersion, supported,
                         current);
}

nvmlReturn_t nvmlSetVgpuVersion(nvmlVgpuVersion_t *vgpuVersion) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSetVgpuVersion, vgpuVersion);
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v3(
    nvmlDevice_t device,
    nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGridLicensableFeatures_v3, device,
                         pGridLicensableFeatures);
}

nvmlReturn_t nvmlDeviceGetHostVgpuMode(nvmlDevice_t device,
                                       nvmlHostVgpuMode_t *pHostVgpuMode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHostVgpuMode, device,
                         pHostVgpuMode);
}

nvmlReturn_t nvmlDeviceGetPgpuMetadataString(nvmlDevice_t device,
                                             char *pgpuMetadata,
                                             unsigned int *bufferSize) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPgpuMetadataString,
                         device, pgpuMetadata, bufferSize);
}

nvmlReturn_t nvmlVgpuInstanceGetEccMode(nvmlVgpuInstance_t vgpuInstance,
                                        nvmlEnableState_t *eccMode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEccMode,
                         vgpuInstance, eccMode);
}

nvmlReturn_t nvmlComputeInstanceDestroy(nvmlComputeInstance_t computeInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceDestroy,
                         computeInstance);
}

nvmlReturn_t nvmlComputeInstanceGetInfo(nvmlComputeInstance_t computeInstance,
                                        nvmlComputeInstanceInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceGetInfo,
                         computeInstance, info);
}

nvmlReturn_t nvmlDeviceCreateGpuInstance(nvmlDevice_t device,
                                         unsigned int profileId,
                                         nvmlGpuInstance_t *gpuInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceCreateGpuInstance,
                         device, profileId, gpuInstance);
}

nvmlReturn_t nvmlDeviceGetArchitecture(nvmlDevice_t device,
                                       nvmlDeviceArchitecture_t *arch) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetArchitecture, device,
                         arch);
}

nvmlReturn_t nvmlDeviceGetAttributes(nvmlDevice_t device,
                                     nvmlDeviceAttributes_t *attributes) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAttributes, device,
                         attributes);
}

nvmlReturn_t nvmlDeviceGetAttributes_v2(nvmlDevice_t device,
                                        nvmlDeviceAttributes_t *attributes) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAttributes_v2, device,
                         attributes);
}

nvmlReturn_t nvmlDeviceGetComputeInstanceId(nvmlDevice_t device,
                                            unsigned int *id) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeInstanceId,
                         device, id);
}

nvmlReturn_t nvmlDeviceGetCpuAffinityWithinScope(nvmlDevice_t device,
                                                 unsigned int cpuSetSize,
                                                 unsigned long *cpuSet,
                                                 nvmlAffinityScope_t scope) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetCpuAffinityWithinScope, device,
                         cpuSetSize, cpuSet, scope);
}

nvmlReturn_t
nvmlDeviceGetDeviceHandleFromMigDeviceHandle(nvmlDevice_t migDevice,
                                             nvmlDevice_t *device) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetDeviceHandleFromMigDeviceHandle,
                         migDevice, device);
}

nvmlReturn_t nvmlDeviceGetGpuInstanceById(nvmlDevice_t device, unsigned int id,
                                          nvmlGpuInstance_t *gpuInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceById,
                         device, id, gpuInstance);
}

nvmlReturn_t nvmlDeviceGetGpuInstanceId(nvmlDevice_t device, unsigned int *id) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceId, device,
                         id);
}

nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements_v2(
    nvmlDevice_t device, unsigned int profileId,
    nvmlGpuInstancePlacement_t *placements, unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGpuInstancePossiblePlacements_v2, device,
                         profileId, placements, count);
}

nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements(
    nvmlDevice_t device, unsigned int profileId,
    nvmlGpuInstancePlacement_t *placements, unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGpuInstancePossiblePlacements, device,
                         profileId, placements, count);
}

nvmlReturn_t
nvmlDeviceGetGpuInstanceProfileInfo(nvmlDevice_t device, unsigned int profile,
                                    nvmlGpuInstanceProfileInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGpuInstanceProfileInfo, device, profile,
                         info);
}

nvmlReturn_t nvmlDeviceGetGpuInstanceRemainingCapacity(nvmlDevice_t device,
                                                       unsigned int profileId,
                                                       unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGpuInstanceRemainingCapacity, device,
                         profileId, count);
}

nvmlReturn_t nvmlDeviceGetGpuInstances(nvmlDevice_t device,
                                       unsigned int profileId,
                                       nvmlGpuInstance_t *gpuInstances,
                                       unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstances, device,
                         profileId, gpuInstances, count);
}

nvmlReturn_t nvmlDeviceGetMaxMigDeviceCount(nvmlDevice_t device,
                                            unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxMigDeviceCount,
                         device, count);
}

nvmlReturn_t nvmlDeviceGetMemoryAffinity(nvmlDevice_t device,
                                         unsigned int nodeSetSize,
                                         unsigned long *nodeSet,
                                         nvmlAffinityScope_t scope) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryAffinity,
                         device, nodeSetSize, nodeSet, scope);
}

nvmlReturn_t nvmlDeviceGetMigDeviceHandleByIndex(nvmlDevice_t device,
                                                 unsigned int index,
                                                 nvmlDevice_t *migDevice) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetMigDeviceHandleByIndex, device, index,
                         migDevice);
}

nvmlReturn_t nvmlDeviceGetMigMode(nvmlDevice_t device,
                                  unsigned int *currentMode,
                                  unsigned int *pendingMode) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMigMode, device,
                         currentMode, pendingMode);
}

nvmlReturn_t nvmlDeviceGetRemappedRows(nvmlDevice_t device,
                                       unsigned int *corrRows,
                                       unsigned int *uncRows,
                                       unsigned int *isPending,
                                       unsigned int *failureOccurred) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRemappedRows, device,
                         corrRows, uncRows, isPending, failureOccurred);
}

nvmlReturn_t
nvmlDeviceGetRowRemapperHistogram(nvmlDevice_t device,
                                  nvmlRowRemapperHistogramValues_t *values) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRowRemapperHistogram,
                         device, values);
}

nvmlReturn_t nvmlDeviceIsMigDeviceHandle(nvmlDevice_t device,
                                         unsigned int *isMigDevice) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceIsMigDeviceHandle,
                         device, isMigDevice);
}

nvmlReturn_t nvmlDeviceSetMigMode(nvmlDevice_t device, unsigned int mode,
                                  nvmlReturn_t *activationStatus) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMigMode, device, mode,
                         activationStatus);
}

nvmlReturn_t nvmlEventSetWait_v2(nvmlEventSet_t set, nvmlEventData_t *data,
                                 unsigned int timeoutms) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetWait_v2, set, data,
                         timeoutms);
}

nvmlReturn_t
nvmlGpuInstanceCreateComputeInstance(nvmlGpuInstance_t gpuInstance,
                                     unsigned int profileId,
                                     nvmlComputeInstance_t *computeInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlGpuInstanceCreateComputeInstance, gpuInstance,
                         profileId, computeInstance);
}

nvmlReturn_t nvmlGpuInstanceDestroy(nvmlGpuInstance_t gpuInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceDestroy,
                         gpuInstance);
}

nvmlReturn_t
nvmlGpuInstanceGetComputeInstanceById(nvmlGpuInstance_t gpuInstance,
                                      unsigned int id,
                                      nvmlComputeInstance_t *computeInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlGpuInstanceGetComputeInstanceById, gpuInstance, id,
                         computeInstance);
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstanceProfileInfo(
    nvmlGpuInstance_t gpuInstance, unsigned int profile,
    unsigned int engProfile, nvmlComputeInstanceProfileInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlGpuInstanceGetComputeInstanceProfileInfo,
                         gpuInstance, profile, engProfile, info);
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstanceRemainingCapacity(
    nvmlGpuInstance_t gpuInstance, unsigned int profileId,
    unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlGpuInstanceGetComputeInstanceRemainingCapacity,
                         gpuInstance, profileId, count);
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstances(
    nvmlGpuInstance_t gpuInstance, unsigned int profileId,
    nvmlComputeInstance_t *computeInstances, unsigned int *count) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstances,
                         gpuInstance, profileId, computeInstances, count);
}

nvmlReturn_t nvmlGpuInstanceGetInfo(nvmlGpuInstance_t gpuInstance,
                                    nvmlGpuInstanceInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetInfo,
                         gpuInstance, info);
}

nvmlReturn_t
nvmlVgpuInstanceClearAccountingPids(nvmlVgpuInstance_t vgpuInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlVgpuInstanceClearAccountingPids, vgpuInstance);
}

nvmlReturn_t nvmlVgpuInstanceGetMdevUUID(nvmlVgpuInstance_t vgpuInstance,
                                         char *mdevUuid, unsigned int size) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetMdevUUID,
                         vgpuInstance, mdevUuid, size);
}

nvmlReturn_t
nvmlComputeInstanceGetInfo_v2(nvmlComputeInstance_t computeInstance,
                              nvmlComputeInstanceInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceGetInfo_v2,
                         computeInstance, info);
}

nvmlReturn_t nvmlDeviceGetComputeRunningProcesses_v2(nvmlDevice_t device,
                                                     unsigned int *infoCount,
                                                     nvmlProcessInfo_t *infos) {
  // LOGGER(5, "Call Rewrite Function: %s\n", "nvmlDeviceGetComputeRunningProcesses_v2");
  // nvmlReturn_t ret;
  // ret = NVML_ENTRY_CALL(nvml_library_entry,
  //                        nvmlDeviceGetComputeRunningProcesses_v2, device,
  //                        infoCount, infos);
  // if (g_vcuda_config.enable && ret == NVML_SUCCESS) {
  //     atomic_action(pid_path, load_pids_table, NULL);
  //     search_on_pids_table(infoCount, infos);
  // }
  // return ret;
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetComputeRunningProcesses_v2, device,
                         infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses_v2(
    nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetGraphicsRunningProcesses_v2, device,
                         infoCount, infos);
}
nvmlReturn_t nvmlDeviceSetTemperatureThreshold(
    nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, int *temp) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetTemperatureThreshold,
                         device, thresholdType, temp);
}

/** no prototype
nvmlReturn_t nvmlRetry_NvRmControl() {}
 */

nvmlReturn_t nvmlVgpuInstanceGetGpuInstanceId(nvmlVgpuInstance_t vgpuInstance,
                                              unsigned int *gpuInstanceId) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetGpuInstanceId,
                         vgpuInstance, gpuInstanceId);
}
nvmlReturn_t
nvmlVgpuTypeGetGpuInstanceProfileId(nvmlVgpuTypeId_t vgpuTypeId,
                                    unsigned int *gpuInstanceProfileId) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlVgpuTypeGetGpuInstanceProfileId, vgpuTypeId,
                         gpuInstanceProfileId);
}

nvmlReturn_t nvmlDeviceCreateGpuInstanceWithPlacement(
    nvmlDevice_t device, unsigned int profileId,
    const nvmlGpuInstancePlacement_t *placement,
    nvmlGpuInstance_t *gpuInstance) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceCreateGpuInstanceWithPlacement, device,
                         profileId, placement, gpuInstance);
}

nvmlReturn_t nvmlDeviceGetBusType(nvmlDevice_t device, nvmlBusType_t *type) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBusType, device,
                         type);
}

nvmlReturn_t nvmlDeviceGetClkMonStatus(nvmlDevice_t device,
                                       nvmlClkMonStatus_t *status) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClkMonStatus, device,
                         status);
}

nvmlReturn_t nvmlDeviceGetIrqNum(nvmlDevice_t device, unsigned int *irqNum) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIrqNum);
}

nvmlReturn_t nvmlDeviceGetNvLinkRemoteDeviceType(
    nvmlDevice_t device, unsigned int link,
    nvmlIntNvLinkDeviceType_t *pNvLinkDeviceType) {
  return NVML_ENTRY_CALL(nvml_library_entry,
                         nvmlDeviceGetNvLinkRemoteDeviceType, device, link,
                         pNvLinkDeviceType);
}

nvmlReturn_t nvmlDeviceResetMemoryLockedClocks(nvmlDevice_t device) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetMemoryLockedClocks,
                         device);
}

nvmlReturn_t nvmlDeviceSetMemoryLockedClocks(nvmlDevice_t device,
                                             unsigned int minMemClockMHz,
                                             unsigned int maxMemClockMHz) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMemoryLockedClocks,
                         device, minMemClockMHz, maxMemClockMHz);
}

nvmlReturn_t nvmlGetExcludedDeviceCount(unsigned int *deviceCount) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetExcludedDeviceCount,
                         deviceCount);
}

nvmlReturn_t nvmlGetExcludedDeviceInfoByIndex(unsigned int index,
                                              nvmlExcludedDeviceInfo_t *info) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetExcludedDeviceInfoByIndex,
                         index, info);
}

nvmlReturn_t
nvmlVgpuInstanceGetLicenseInfo(nvmlVgpuInstance_t vgpuInstance,
                               nvmlVgpuLicenseInfo_t *licenseInfo) {
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseInfo, vgpuInstance, licenseInfo);
}

nvmlReturn_t 
nvmlDeviceClearFieldValues ( nvmlDevice_t device, int  valuesCount, 
                              nvmlFieldValue_t* values ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearFieldValues, device, valuesCount, values);
}

nvmlReturn_t 
nvmlDeviceGetAdaptiveClockInfoStatus ( nvmlDevice_t device, unsigned int* adaptiveClockStatus ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAdaptiveClockInfoStatus, device, adaptiveClockStatus);
}

nvmlReturn_t
nvmlDeviceGetComputeRunningProcesses_v3 ( nvmlDevice_t device, unsigned int* infoCount, nvmlProcessInfo_t* infos ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeRunningProcesses_v3, device, infoCount, infos);
}

nvmlReturn_t 
nvmlDeviceGetDefaultEccMode(nvmlDevice_t device, nvmlEnableState_t* defaultMode ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDefaultEccMode, device, defaultMode);
}

nvmlReturn_t 
nvmlDeviceGetDynamicPstatesInfo(nvmlDevice_t device, nvmlGpuDynamicPstatesInfo_t* pDynamicPstatesInfo ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDynamicPstatesInfo, device, pDynamicPstatesInfo);
}

// nvmlReturn_t 
// nvmlDeviceGetFanControlPolicy(nvmlDevice_t device, unsigned int  fan, 
//                                     nvmlFanControlPolicy_t policy){
//   return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanControlPolicy, device, fan, policy);                                  
// }

nvmlReturn_t 
nvmlDeviceGetFanControlPolicy_v2(nvmlDevice_t device, unsigned int  fan, 
                                    nvmlFanControlPolicy_t* policy){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanControlPolicy_v2, device, fan, policy);                                  
}

nvmlReturn_t 
nvmlDeviceGetGpcClkMinMaxVfOffset ( nvmlDevice_t device, int* minOffset, int* maxOffset ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpcClkMinMaxVfOffset, device, minOffset, maxOffset);
}

nvmlReturn_t 
nvmlDeviceGetGpcClkVfOffset ( nvmlDevice_t device, int* offset ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpcClkVfOffset, device, offset);
}

nvmlReturn_t 
nvmlDeviceGetGpuFabricInfo ( nvmlDevice_t device, nvmlGpuFabricInfo_t* gpuFabricInfo ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuFabricInfo, device, gpuFabricInfo);
}

nvmlReturn_t 
nvmlDeviceGetGpuInstanceProfileInfoV ( nvmlDevice_t device, unsigned int  profile, 
                                        nvmlGpuInstanceProfileInfo_v2_t* info ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceProfileInfoV, device, profile, info);
}

nvmlReturn_t 
nvmlDeviceGetGpuMaxPcieLinkGeneration ( nvmlDevice_t device, unsigned int* maxLinkGenDevice ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuMaxPcieLinkGeneration, device, maxLinkGenDevice);
}

nvmlReturn_t 
nvmlDeviceGetGraphicsRunningProcesses_v3 ( nvmlDevice_t device, unsigned int* infoCount, nvmlProcessInfo_t* infos ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGraphicsRunningProcesses_v3, device, infoCount, infos);
}

nvmlReturn_t 
nvmlDeviceGetGspFirmwareMode ( nvmlDevice_t device, unsigned int* isEnabled, unsigned int* defaultMode ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGspFirmwareMode, device, isEnabled, defaultMode);
}

nvmlReturn_t 
nvmlDeviceGetGspFirmwareVersion ( nvmlDevice_t device, char* version ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGspFirmwareVersion, device, version);
}

nvmlReturn_t
nvmlDeviceGetJpgUtilization(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetJpgUtilization, device, utilization, samplingPeriodUs);
}

nvmlReturn_t 
nvmlDeviceGetMemClkMinMaxVfOffset ( nvmlDevice_t device, int* minOffset, int* maxOffset ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemClkMinMaxVfOffset, device, minOffset, maxOffset);
}

nvmlReturn_t 
nvmlDeviceGetMemClkVfOffset ( nvmlDevice_t device, int* offset ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemClkVfOffset, device, offset);
}

nvmlReturn_t 
nvmlDeviceGetMemoryBusWidth ( nvmlDevice_t device, unsigned int* busWidth ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryBusWidth, device, busWidth);
}

nvmlReturn_t 
nvmlDeviceGetMinMaxClockOfPState ( nvmlDevice_t device, nvmlClockType_t type, 
            nvmlPstates_t pstate, unsigned int* minClockMHz, unsigned int* maxClockMHz ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMinMaxClockOfPState, device, type, pstate, minClockMHz, maxClockMHz);
}

nvmlReturn_t 
nvmlDeviceGetMinMaxFanSpeed ( nvmlDevice_t device, unsigned int* minSpeed, unsigned int* maxSpeed ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMinMaxFanSpeed, device, minSpeed, maxSpeed);
}

nvmlReturn_t
nvmlDeviceGetModuleId(nvmlDevice_t device, unsigned int *moduleId){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetModuleId, device, moduleId);
}

nvmlReturn_t 
nvmlDeviceGetMPSComputeRunningProcesses_v3 ( nvmlDevice_t device, unsigned int* infoCount,
                                             nvmlProcessInfo_t* infos ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMPSComputeRunningProcesses_v3, device, infoCount, infos);
}

nvmlReturn_t nvmlDeviceGetNumFans ( nvmlDevice_t device, unsigned int* numFans ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNumFans, device, numFans);
}


nvmlReturn_t nvmlDeviceGetNumGpuCores ( nvmlDevice_t device, unsigned int* numCores ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNumGpuCores, device, numCores);
}

nvmlReturn_t
nvmlDeviceGetOfaUtilization(nvmlDevice_t device, unsigned int *utilization,
                                           unsigned int *samplingPeriodUs){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetOfaUtilization, device, utilization, samplingPeriodUs);
}

nvmlReturn_t nvmlDeviceGetPcieLinkMaxSpeed ( nvmlDevice_t device, unsigned int* maxSpeed ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieLinkMaxSpeed, device, maxSpeed);
}

nvmlReturn_t nvmlDeviceGetPcieSpeed ( nvmlDevice_t device, unsigned int* pcieSpeed ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieSpeed, device, pcieSpeed);
}

nvmlReturn_t nvmlDeviceGetPowerSource ( nvmlDevice_t device, nvmlPowerSource_t* powerSource ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerSource, device, powerSource);
}

nvmlReturn_t 
nvmlDeviceGetSupportedClocksEventReasons(nvmlDevice_t device, unsigned long long *supportedClocksEventReasons){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedClocksEventReasons, device, supportedClocksEventReasons);
}

nvmlReturn_t 
nvmlDeviceGetSupportedPerformanceStates ( nvmlDevice_t device, nvmlPstates_t* pstates, unsigned int  size ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedPerformanceStates, device, pstates, size);
}

nvmlReturn_t 
nvmlDeviceGetTargetFanSpeed ( nvmlDevice_t device, unsigned int  fan, unsigned int* targetSpeed ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTargetFanSpeed, device, fan, targetSpeed);
}

nvmlReturn_t 
nvmlDeviceGetThermalSettings ( nvmlDevice_t device, unsigned int  sensorIndex,
                               nvmlGpuThermalSettings_t* pThermalSettings ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetThermalSettings, device, sensorIndex, pThermalSettings);
}

nvmlReturn_t 
nvmlDeviceGetVgpuCapabilities ( nvmlDevice_t device, nvmlDeviceVgpuCapability_t capability, unsigned int* capResult ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuCapabilities, device, capability, capResult);
}

nvmlReturn_t 
nvmlGetVgpuDriverCapabilities ( nvmlVgpuDriverCapability_t capability, unsigned int* capResult ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuDriverCapabilities, capability, capResult);
}

nvmlReturn_t 
nvmlDeviceGetVgpuSchedulerCapabilities ( nvmlDevice_t device, nvmlVgpuSchedulerCapabilities_t* pCapabilities ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuSchedulerCapabilities, device, pCapabilities);
}

nvmlReturn_t 
nvmlDeviceGetVgpuSchedulerLog ( nvmlDevice_t device, nvmlVgpuSchedulerLog_t* pSchedulerLog ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuSchedulerLog, device, pSchedulerLog);
}

nvmlReturn_t 
nvmlDeviceGetVgpuSchedulerState ( nvmlDevice_t device, nvmlVgpuSchedulerGetState_t* pSchedulerState){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuSchedulerState, device, pSchedulerState);
}

nvmlReturn_t 
nvmlDeviceSetVgpuSchedulerState ( nvmlDevice_t device, nvmlVgpuSchedulerSetState_t* pSchedulerState ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetVgpuSchedulerState, device, pSchedulerState);
}

nvmlReturn_t 
nvmlDeviceSetConfComputeUnprotectedMemSize(nvmlDevice_t device, unsigned long long sizeKiB){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetConfComputeUnprotectedMemSize, device, sizeKiB);
}

nvmlReturn_t nvmlDeviceSetDefaultFanSpeed_v2 ( nvmlDevice_t device, unsigned int  fan){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetDefaultFanSpeed_v2, device, fan);
}

nvmlReturn_t 
nvmlDeviceSetFanControlPolicy ( nvmlDevice_t device, unsigned int  fan, nvmlFanControlPolicy_t policy ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetFanControlPolicy, device, fan, policy);
}

nvmlReturn_t 
nvmlDeviceSetFanSpeed_v2 ( nvmlDevice_t device, unsigned int  fan, unsigned int  speed ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetFanSpeed_v2, device, fan, speed);
}

nvmlReturn_t 
nvmlDeviceSetGpcClkVfOffset ( nvmlDevice_t device, int  offset ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpcClkVfOffset, device, offset);
}

nvmlReturn_t 
nvmlDeviceSetMemClkVfOffset ( nvmlDevice_t device, int  offset ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMemClkVfOffset, device, offset);
}

nvmlReturn_t 
nvmlDeviceSetNvLinkDeviceLowPowerThreshold(nvmlDevice_t device, nvmlNvLinkPowerThres_t *info){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetNvLinkDeviceLowPowerThreshold, device, info);
}

nvmlReturn_t 
nvmlDeviceSetPowerManagementLimit_v2(nvmlDevice_t device, nvmlPowerValue_v2_t *powerValue){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPowerManagementLimit_v2, device, powerValue);
}

nvmlReturn_t nvmlGpmMetricsGet(nvmlGpmMetricsGet_t *metricsGet){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmMetricsGet, metricsGet);
}

nvmlReturn_t 
nvmlGpmMigSampleGet(nvmlDevice_t device, unsigned int gpuInstanceId, nvmlGpmSample_t gpmSample){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmMigSampleGet, device, gpuInstanceId, gpmSample);
}

nvmlReturn_t 
nvmlGpmQueryDeviceSupport(nvmlDevice_t device, nvmlGpmSupport_t *gpmSupport){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmQueryDeviceSupport, gpmSupport);
}

nvmlReturn_t 
nvmlGpmQueryIfStreamingEnabled(nvmlDevice_t device, unsigned int *state){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmQueryIfStreamingEnabled, device, state);
}

nvmlReturn_t nvmlGpmSampleAlloc(nvmlGpmSample_t *gpmSample){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmSampleAlloc, gpmSample);
}

nvmlReturn_t nvmlGpmSampleFree(nvmlGpmSample_t gpmSample){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmSampleFree, gpmSample);
}

nvmlReturn_t nvmlGpmSampleGet(nvmlDevice_t device, nvmlGpmSample_t gpmSample){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmSampleGet, device, gpmSample);
}

nvmlReturn_t 
nvmlGpmSetStreamingEnabled(nvmlDevice_t device, unsigned int state){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpmSetStreamingEnabled, device, state);
}

nvmlReturn_t
nvmlGpuInstanceCreateComputeInstanceWithPlacement ( nvmlGpuInstance_t gpuInstance, unsigned int  profileId, 
                                const nvmlComputeInstancePlacement_t* placement, 
                                nvmlComputeInstance_t* computeInstance ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceCreateComputeInstanceWithPlacement, gpuInstance, profileId, placement, computeInstance);
}

nvmlReturn_t 
nvmlGpuInstanceGetComputeInstancePossiblePlacements ( nvmlGpuInstance_t gpuInstance, unsigned int  profileId, 
                                nvmlComputeInstancePlacement_t* placements, unsigned int* count ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstancePossiblePlacements, gpuInstance, profileId, placements, count);
}

nvmlReturn_t 
nvmlGpuInstanceGetComputeInstanceProfileInfoV ( nvmlGpuInstance_t gpuInstance, unsigned int  profile, unsigned int  engProfile, nvmlComputeInstanceProfileInfo_v2_t* info ){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceProfileInfoV, gpuInstance, profile, engProfile, info);
}

nvmlReturn_t 
nvmlSystemGetConfComputeCapabilities(nvmlConfComputeSystemCaps_t *capabilities){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetConfComputeCapabilities, capabilities);
}

nvmlReturn_t 
nvmlSystemGetConfComputeGpusReadyState(unsigned int *isAcceptingWork){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetConfComputeGpusReadyState, isAcceptingWork);
}

nvmlReturn_t
nvmlSystemGetConfComputeState(nvmlConfComputeSystemState_t *state){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetConfComputeState, state);
}

nvmlReturn_t nvmlSystemGetNvlinkBwMode(unsigned int *nvlinkBwMode){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetNvlinkBwMode, nvlinkBwMode);
}

nvmlReturn_t nvmlSystemSetConfComputeGpusReadyState(unsigned int isAcceptingWork){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemSetConfComputeGpusReadyState, isAcceptingWork);
}

nvmlReturn_t nvmlSystemSetNvlinkBwMode(unsigned int nvlinkBwMode){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemSetNvlinkBwMode, nvlinkBwMode);
}

nvmlReturn_t 
nvmlVgpuInstanceGetGpuPciId(nvmlVgpuInstance_t vgpuInstance, char *vgpuPciId, 
                                                            unsigned int *length){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetGpuPciId, vgpuInstance, vgpuPciId, length);
}

nvmlReturn_t 
nvmlVgpuInstanceGetLicenseInfo_v2(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t *licenseInfo){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseInfo_v2, vgpuInstance, licenseInfo);
}

nvmlReturn_t 
nvmlVgpuTypeGetCapabilities(nvmlVgpuTypeId_t vgpuTypeId, nvmlVgpuCapability_t capability, unsigned int *capResult){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetCapabilities, vgpuTypeId, capability, capResult);
}

nvmlReturn_t 
nvmlDeviceGetCurrentClocksEventReasons(nvmlDevice_t device, unsigned long long *clocksEventReasons){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrentClocksEventReasons, device, clocksEventReasons);
}

nvmlReturn_t 
nvmlDeviceGetConfComputeProtectedMemoryUsage(nvmlDevice_t device, nvmlMemory_t *memory){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetConfComputeProtectedMemoryUsage, device, memory);
}

nvmlReturn_t 
nvmlDeviceGetConfComputeMemSizeInfo(nvmlDevice_t device, nvmlConfComputeMemSizeInfo_t *memInfo){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetConfComputeMemSizeInfo, device, memInfo);
}

nvmlReturn_t 
nvmlDeviceGetConfComputeGpuCertificate(nvmlDevice_t device,
                                       nvmlConfComputeGpuCertificate_t *gpuCert){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetConfComputeGpuCertificate, device, gpuCert);
}

nvmlReturn_t 
nvmlDeviceGetConfComputeGpuAttestationReport(nvmlDevice_t device,
                                            nvmlConfComputeGpuAttestationReport_t *gpuAtstReport){
  return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetConfComputeGpuAttestationReport, device, gpuAtstReport);
}
