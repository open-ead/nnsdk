#pragma once

#include <nn/err/err_ApplicationErrorArg.h>
#include <nn/err/err_ErrorCode.h>
#include <nn/err/err_ErrorMessageDatabaseVersion.h>
#include <nn/err/err_ErrorResultVariant.h>
#include <nn/err/err_ResultBacktrace.h>
#include <nn/err/err_SystemErrorArg.h>
#include <nn/nn_Result.h>
#include <nn/settings.h>
#include <nn/time.h>

namespace nn::err {
class EulaData;                       // TODO
class ErrorViewerJumpDestination {};  // TODO

ErrorCode ConvertResultToErrorCode(const Result& result);
bool CreateErrorViewerStartupParamForRecordedError(void*, std::uint64_t*, std::uint64_t,
                                                   const char*, const char*, time::PosixTime);
void ExecuteJump(ErrorViewerJumpDestination destination);
void GetErrorCodeString(char* outErrorCodeString, std::size_t errorCodeStrBufferSize,
                        ErrorCode errorCode);
void* GetErrorMessageDatabaseVersion(ErrorMessageDatabaseVersion* outVersion);
ErrorCode MakeErrorCode(std::uint32_t category, std::uint32_t number);
void ShowApplicationError(const ApplicationErrorArg& arg);
void ShowError(Result result);
void ShowError(ErrorCode errorCode);
void ShowError(const ErrorResultVariant& errorResultVariant);
void ShowError(Result result, ResultBacktrace& backtrace);
void ShowErrorRecord(Result result, time::PosixTime timestamp);
void ShowErrorRecord(ErrorCode errorCode, time::PosixTime timestamp);
void ShowErrorRecord(const void*, std::uint64_t);
void ShowErrorWithoutJump(Result result);
void ShowErrorWithoutJump(ErrorCode errorCode);
void ShowEula(settings::system::RegionCode regionCode);
void ShowSystemError(const SystemErrorArg& arg);
void ShowSystemUpdateEula(settings::system::RegionCode regionCode, EulaData& data);
void ShowUnacceptableAddOnContentVersionError();
void ShowUnacceptableApplicationVersionError();
}  // namespace nn::err
