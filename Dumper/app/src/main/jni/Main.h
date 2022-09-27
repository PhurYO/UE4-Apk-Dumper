//
// Created by Ascarre on 26-09-2022.
//

#ifndef PRIVATE_DUMPER_MAIN_H
#define PRIVATE_DUMPER_MAIN_H

#include "Canvas.h"
#include "Dumper.h"

void RenderHacks(Canvas Draw, int SWidth, int SHeight) {
    Draw.DrawText(Color(255, 40, 40), "Made By Ascarre", Vector2(SWidth / 8, SHeight / 12), 25);

    ProcessId = FindProcessId(Offsets::ProcessName);
    ModuleBase = GetModuleBase(ProcessId, Offsets::ModuleName);
    ModuleEnd = GetModuleEnd(ProcessId, Offsets::ModuleName);

    string OutputDirectory = "/sdcard/DumpedGames/";
    OutputDirectory += Offsets::ProcessName;

    if (isEqual(Offsets::ProcessName, "com.tencent.ig") || isEqual(Offsets::ProcessName, "com.pubg.imobile")){
        Offsets::PubgMobile();
        isPubg = true;
    } else if (isEqual(Offsets::ProcessName, "com.tencent.iglite")){
        Offsets::PubgLite();
        isPubgLite = true;
    } else if (Offsets::ProcessName, "Other_Game_Package_Name") {
        //Uncomment with offset function Name after adding the function in Offsets.h file
        //Offsets::Testing_Game();

        //Choose from these and uncomment rest, You can choose as many you Need.
        //Like if Game is 4.23+ and needs XOR Decrypt then use both 1 and 2 option
		
        isUE423 = true;//1
        isDecrypt = true;//2
        isPubgLite = true;//3
        isPubg = true;//4
    }

    /******************** Dumping Functions ********************/
    //LibDump
    if (isLibDump && !LibDumped) {
        LibDumped = true;
        LibDump(OutputDirectory);
    }

    //Strings Dump
    if (isStringDump && !StringDumped) {
        StringDumped = true;
        DumpStrings(OutputDirectory);
    }

    //Objects Dump
    if (isObjectDump && !ObjectDump) {
        ObjectDump = true;
        DumpObjects(OutputDirectory);
    }

    //SDKW Dump using GWorld
    if (isSDKWDump && !SDKWDumped) {
        SDKWDumped = true;
        DumpSDKW(OutputDirectory);
    }

    //SDK Dump using GUObject
    if (isSDKDump && !SDKDumped) {
        SDKDumped = true;
        DumpSDK(OutputDirectory);
    }

    if (isFindActors && !FoundActors) {
        FoundActors = true;
        DumpActors(OutputDirectory);
    }
}

#endif //PRIVATE_DUMPER_MAIN_H
