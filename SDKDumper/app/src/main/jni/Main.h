//
// Created by Ascarre on 09-05-2022.
//

#ifndef SDKGENERATOR_MAIN_H
#define SDKGENERATOR_MAIN_H

#include "Dumper.h"
#include "Canvas.h"

bool StringsDumped = false, ObjectsDumped = false, SdkDumped = false, SdkWDumped = false;

void RenderHacks(Canvas Draw, int SWidth, int SHeight) {
    Draw.DrawText(Color(255,40,40), "Dumper Made By Ascarre", Vector2(SWidth / 8, SHeight / 8), 25);

    ProcessId = FindProcessId(Offsets::ProcessName);
    ModuleBase = GetModuleBase(ProcessId, Offsets::ModuleName);
    ModuleEnd = GetModuleEnd(ProcessId, Offsets::ModuleName);

    if (isStringDump && StringsDumped == false) {
        StringsDumped = true;
        DumpStrings(ModuleBase);
    }

    if (isObjectsDump && ObjectsDumped == false) {
        ObjectsDumped = true;
        DumpObjects(ModuleBase);
    }

    if (isSdkDump && SdkDumped == false) {
        SdkDumped = true;
        DumpSDK(ModuleBase);
    }

    if (isSdkWDump && SdkWDumped == false) {
        SdkWDumped = true;
        DumpSDKW(ModuleBase);
    }
}

#endif //SDKGENERATOR_MAIN_H
