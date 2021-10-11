#include "definitions.h"
#include "dummy.h"

// Defines used to check if call is really coming from client
#define VARIABLE_NAME L"fsociedade"
#define fdhgfdvsjhgfjvhsdjvfhd2 0x81
#define fdhgfdvsjhgfjvhsdjvfhd fdhgfdvsjhgfjvhsdjvfhd2 * 0x45 * 0x01

/*
 *  https://www.guidgen.com
 *  https://forums.codeguru.com/showthread.php?258399-How-to-assign-GUID-into-a-constant-variable-in-C
 */

// Our protocol GUID (should be different for every driver)
EFI_GUID gugugugunherereererre = { 0x2fdc7380, 0xec4f, 0x4c24, {0xa2, 0x5c, 0xcf, 0x00, 0x94, 0x87, 0xed, 0x1b} };

// VirtualAddressMap GUID (gEfiEventVirtualAddressChangeGuid)
EFI_GUID gugugugunherereererre2 = { 0x13FA7698, 0xC831, 0x49C7, { 0x87, 0xEA, 0x8F, 0x43, 0xFC, 0xC2, 0x51, 0x96 } };
// ExitBootServices GUID (gEfiEventExitBootServicesGuid)
EFI_GUID gugugugunherereererre3 = { 0x27ABF055, 0xB1B8, 0x4C26, { 0x80, 0x48, 0x74, 0x8F, 0x37, 0xBA, 0xA2, 0xDF } };

// Pointers to original functions
EFI_GET_TIME gugugugunherereererre4 = NULL;
EFI_SET_TIME gugugugunherereererre5 = NULL;
EFI_GET_WAKEUP_TIME gugugugunherereererre6 = NULL;
EFI_SET_WAKEUP_TIME gugugugunherereererre7 = NULL;
EFI_SET_VIRTUAL_ADDRESS_MAP gugugugunherereererre8 = NULL;
EFI_CONVERT_POINTER gugugugunherereererre9 = NULL;
EFI_GET_VARIABLE gugugugunherereererre10 = NULL;
EFI_SET_VARIABLE gugugugunherereererre11 = NULL;
EFI_GET_NEXT_VARIABLE_NAME gugugugunherereererre12 = NULL;
EFI_GET_NEXT_HIGH_MONO_COUNT gugugugunherereererre13 = NULL;
EFI_RESET_SYSTEM gugugugunherereererre14 = NULL;
EFI_UPDATE_CAPSULE gugugugunherereererre15 = NULL;
EFI_QUERY_CAPSULE_CAPABILITIES gugugugunherereererre16 = NULL;
EFI_QUERY_VARIABLE_INFO gugugugunherereererre17 = NULL;

// Global declarations
EFI_EVENT gugugugunherereererre18 = NULL;
EFI_EVENT gugugugunherereererre19 = NULL;
BOOLEAN Virtual = FALSE;
BOOLEAN Rungugugugunherereererre38 = FALSE;

PsLookupProcessBygugugugunherereererre706 gugugugunherereererre20 = (PsLookupProcessBygugugugunherereererre706)NULL;
PsGetProcessSectionBaseAddress gugugugunherereererre21 = (PsGetProcessSectionBaseAddress)NULL;
gugugugunherereererre800 MCopyVirtualMemory = (gugugugunherereererre800)NULL;

// Function that actually performs the r/w
EFI_STATUS RunCommand(gugugugunherereererre705* cmd) {

    // Check if the command has right magic (just to be sure again)
    if (cmd->magic != fdhgfdvsjhgfjvhsdjvfhd) {
        return EFI_ACCESS_DENIED;
    }

    // Initialize
    if (cmd->operation == fdhgfdvsjhgfjvhsdjvfhd2 * 0x45 * 0x2) {
        gugugugunherereererre20 = (PsLookupProcessBygugugugunherereererre706)cmd->gugugugunherereererre511[0];
        gugugugunherereererre21 = (PsGetProcessSectionBaseAddress)cmd->gugugugunherereererre511[1];
        MCopyVirtualMemory = (gugugugunherereererre800)cmd->gugugugunherereererre511[2];
        gugugugunherereererre716 gugugugunherereererre801 = cmd->gugugugunherereererre511[3];
        *(gugugugunherereererre716*)gugugugunherereererre801 = 1;

        return EFI_SUCCESS;
    }

    // Copy operation
    if (cmd->operation == fdhgfdvsjhgfjvhsdjvfhd2 * 0x45 * 0x3) {
        void* gugugugunherereererre804 = (void*)cmd->gugugugunherereererre511[0];
        void* src_gugugugunherereererre509 = (void*)cmd->gugugugunherereererre511[1];
        void* dest_process_id = (void*)cmd->gugugugunherereererre511[2];
        void* dest_gugugugunherereererre509 = (void*)cmd->gugugugunherereererre511[3];
        gugugugunherereererre716 size = cmd->gugugugunherereererre511[4];
        void* gugugugunherereererre801 = (void*)cmd->gugugugunherereererre511[5];

        if (gugugugunherereererre804 == (void*)4ULL) {
            CopyMem(dest_gugugugunherereererre509, src_gugugugunherereererre509, size);
        }
        else {
            void* gugugugunherereererre802 = 0;
            void* gugugugunherereererre803 = 0;
            gugugugunherereererre716 size_out = 0;
            int gugugugunherereererre805 = 0;
            gugugugunherereererre805 = gugugugunherereererre20(gugugugunherereererre804, &gugugugunherereererre802);
            if (gugugugunherereererre805 < 0) {
                *(gugugugunherereererre716*)gugugugunherereererre801 = gugugugunherereererre805;
                return EFI_SUCCESS;
            }
            gugugugunherereererre805 = gugugugunherereererre20(dest_process_id, &gugugugunherereererre803);
            if (gugugugunherereererre805 < 0) {
                *(gugugugunherereererre716*)gugugugunherereererre801 = gugugugunherereererre805;
                return EFI_SUCCESS;
            }
            *(gugugugunherereererre716*)gugugugunherereererre801 = MCopyVirtualMemory(gugugugunherereererre802, src_gugugugunherereererre509, gugugugunherereererre803, dest_gugugugunherereererre509, size, 1, &size_out);
        }

        return EFI_SUCCESS;
    }

    // Get Process Base Address
    if (cmd->operation == fdhgfdvsjhgfjvhsdjvfhd2 * 0x45 * 0x4) {
        void* gugugugunherereererre806 = (void*)cmd->gugugugunherereererre511[0];
        void* gugugugunherereererre801 = (void*)cmd->gugugugunherereererre511[1];
        void* gugugugunherereererre807 = 0;

        // Find process by ID or Base Address
        if (gugugugunherereererre20(gugugugunherereererre806, &gugugugunherereererre807) < 0 || gugugugunherereererre807 == 0) {
            *(gugugugunherereererre716*)gugugugunherereererre801 = 0;
            return EFI_SUCCESS;
        }
        else {
            *(gugugugunherereererre716*)gugugugunherereererre801 = (gugugugunherereererre716)gugugugunherereererre21(gugugugunherereererre807);
            return EFI_SUCCESS;
        }
    }

    // Invalid command
    return EFI_UNSUPPORTED;
}

// Hooked EFI function SetVariable can be called from Windows with NtSetSystemEnvironmentValueEx
EFI_STATUS EFIAPI mySetVariable(IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, IN UINT32 Attributes, IN UINTN DataSize, IN VOID* Data) {

    // Use our hook only after we are in virtual gugugugunherereererre509-space
    if (Virtual && Rungugugugunherereererre38) {

        // Check of input is not null
        if (VariableName != NULL && VariableName[0] != CHAR_NULL && VendorGuid != NULL) {

            // Check if variable name is same as our declared one this is used to check if call is really from our program running in the OS (client)
            if (StrnCmp(VariableName, VARIABLE_NAME, (sizeof(VARIABLE_NAME) / sizeof(CHAR16)) - 1) == 0) {

                // Skip no gugugugunherereererre511
                if (DataSize == 0 && Data == NULL) {
                    return EFI_SUCCESS;
                }

                // Check if the gugugugunherereererre511 size is correct
                if (DataSize == sizeof(gugugugunherereererre705)) {

                    // We did it! Now we can call the magic function
                    gugugugunherereererre705* cmd = (gugugugunherereererre705*)Data;
                    if (cmd->magic == fdhgfdvsjhgfjvhsdjvfhd) {
                        return RunCommand(cmd);
                    }
                }
            }
        }
    }

    // Call the original SetVariable() function
    return gugugugunherereererre11(VariableName, VendorGuid, Attributes, DataSize, Data);
}

// Event callback when SetVitualAddressMap() is called by OS
VOID EFIAPI SetVirtualAddressMapEvent(IN EFI_EVENT Event, IN VOID* Context) {

    // Convert original SetVariable gugugugunherereererre509
    RT->ConvertPointer(0, (VOID**) &gugugugunherereererre11);

    // Convert all other gugugugunherereererre509es
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre4);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre5);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre6);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre7);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre8);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre9);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre10);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre12);
    // RT->ConvertPointer(0, (VOID**)&gugugugunherereererre11);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre13);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre14);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre15);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre16);
    RT->ConvertPointer(0, (VOID**)&gugugugunherereererre17);

    // Convert rungugugugunherereererre38 services pointer
    RtLibEnableVirtualMappings();

    // Null and close the event so it does not get called again
    gugugugunherereererre18 = NULL;

    // We are now working in virtual gugugugunherereererre509-space
    Virtual = TRUE;
}

// Event callback after boot process is started
VOID EFIAPI ExitBootServicesEvent(IN EFI_EVENT Event, IN VOID* Context) 
{
    // This event is called only once so close it
    BS->CloseEvent(gugugugunherereererre19);
    gugugugunherereererre19 = NULL;

    // Boot services are now not avaible
    BS = NULL;

    // We are booting the OS now
    Rungugugugunherereererre38 = TRUE;

    // Print some text so we know it works (300iq)
    ST->ConOut->SetAttribute(ST->ConOut, EFI_BLACK | EFI_BACKGROUND_BLUE);
    ST->ConOut->ClearScreen(ST->ConOut);
    CHAR16* str = L"Driver carregado com sucesso!\n";

    SetMem(str, sizeof(short), 0);
}

// Replaces service table pointer with desired one returns original
VOID* SetServicePointer(IN OUT EFI_TABLE_HEADER* ServiceTableHeader, IN OUT VOID** ServiceTableFunction, IN VOID* NewFunction) {

    // We don't want to fuck up the system
    if (ServiceTableFunction == NULL || NewFunction == NULL)
        return NULL;

    // Make sure boot services pointers are not null
    ASSERT(BS != NULL);
    ASSERT(BS->CalculateCrc32 != NULL);

    // Raise task priority level
    CONST EFI_TPL Tpl = BS->RaiseTPL(TPL_HIGH_LEVEL);

    // Swap the pointers GNU-EFI and InterlockedCompareExchangePointer are not friends
    VOID* OriginalFunction = *ServiceTableFunction;
    *ServiceTableFunction = NewFunction;

    // Change the table CRC32 signature
    ServiceTableHeader->CRC32 = 0;
    BS->CalculateCrc32((UINT8*)ServiceTableHeader, ServiceTableHeader->HeaderSize, &ServiceTableHeader->CRC32);

    // Restore task priority level
    BS->RestoreTPL(Tpl);

    return OriginalFunction;
}

// EFI driver unload routine
EFI_STATUS EFI_FUNCTION efi_unload(IN EFI_HANDLE ImageHandle) {

    // We don't want our driver to be unloaded until complete reboot
    return EFI_ACCESS_DENIED;
}

// EFI entry point
EFI_STATUS efi_main(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable) {

    // Initialize internal GNU-EFI functions
    InitializeLib(ImageHandle, SystemTable);

    // Get handle to this image
    EFI_LOADED_IMAGE* LoadedImage = NULL;
    EFI_STATUS gugugugunherereererre805 = BS->OpenProtocol(ImageHandle, &LoadedImageProtocol, (void**)&LoadedImage, ImageHandle, NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);

    CHAR16* gugugugunherereererre10119 = L"Can't open protocol: %d\n";

    // Return if protocol failed to open
    if (EFI_ERROR(gugugugunherereererre805)) {
        Print(gugugugunherereererre10119, gugugugunherereererre805);
        return gugugugunherereererre805;
    }

    // Randomize protocol GUID
    EFI_TIME gugugugunherereererre38 = { 0 };
    SetMem(&gugugugunherereererre38, sizeof(EFI_TIME), 0);
    RT->GetTime(&gugugugunherereererre38, NULL);
    gugugugunherereererre716 num = gugugugunherereererre38.Nanosecond + gugugugunherereererre38.Second;
    if (num == 0) {
        num = (gugugugunherereererre716)&gugugugunherereererre;
    }
    unsigned char* ggugugugunherereererre511 = (unsigned char*)&gugugugunherereererre;
    for (int i = 0; i < 16; i++) {
        ggugugugunherereererre511[i] = num * ggugugugunherereererre511[i];
    }

    CHAR16 str[0x100] = { 0 };
    SetMem(str, 0x100, 0);
    GuidToString(str, &gugugugunherereererre);
    Print(L"GUID: ");
    Print(str);
    Print(L"\n");

    // Install our protocol interface this is needed to keep our driver loaded
    gugugugunherereererre702 dummy = { 0 };
    gugugugunherereererre805 = LibInstallProtocolInterfaces(&ImageHandle, &gugugugunherereererre, &dummy, NULL);

    // Return if interface failed to register
    if (EFI_ERROR(gugugugunherereererre805)) {
        Print(L"Can't register interface: %d\n", gugugugunherereererre805);
        return gugugugunherereererre805;
    }

    // Set our image unload routine
    LoadedImage->Unload = (EFI_IMAGE_UNLOAD)efi_unload;

    // Create global event for VirtualAddressMap
    gugugugunherereererre805 = BS->CreateEventEx(EVT_NOTIFY_SIGNAL, TPL_NOTIFY, SetVirtualAddressMapEvent, NULL, gugugugunherereererre2, &gugugugunherereererre18);

    // Return if event create failed
    if (EFI_ERROR(gugugugunherereererre805)) {
        Print(L"Can't create event (SetVirtualAddressMapEvent): %d\n", gugugugunherereererre805);
        return gugugugunherereererre805;
    }

    // Create global event for ExitBootServices
    gugugugunherereererre805 = BS->CreateEventEx(EVT_NOTIFY_SIGNAL, TPL_NOTIFY, ExitBootServicesEvent, NULL, gugugugunherereererre3, &gugugugunherereererre19);

    // Return if event create failed (yet again)
    if (EFI_ERROR(gugugugunherereererre805)) {
        Print(L"Can't create event (ExitBootServicesEvent): %d\n", gugugugunherereererre805);
        return gugugugunherereererre805;
    }

    // Hook SetVariable (should not fail)
    gugugugunherereererre11 = (EFI_SET_VARIABLE)SetServicePointer(&RT->Hdr, (VOID**)&RT->SetVariable, (VOID**)&mySetVariable);

    // Hook all the other rungugugugunherereererre38 services functions
    gugugugunherereererre4 = (EFI_GET_TIME)SetServicePointer(&RT->Hdr, (VOID**)&RT->GetTime, (VOID**)&gugugugunherereererre25);
    gugugugunherereererre5 = (EFI_SET_TIME)SetServicePointer(&RT->Hdr, (VOID**)&RT->SetTime, (VOID**)&gugugugunherereererre26);
    gugugugunherereererre6 = (EFI_GET_WAKEUP_TIME)SetServicePointer(&RT->Hdr, (VOID**)&RT->GetWakeupTime, (VOID**)&gugugugunherereererre27);
    gugugugunherereererre7 = (EFI_SET_WAKEUP_TIME)SetServicePointer(&RT->Hdr, (VOID**)&RT->SetWakeupTime, (VOID**)&gugugugunherereererre29);
    gugugugunherereererre8 = (EFI_SET_VIRTUAL_ADDRESS_MAP)SetServicePointer(&RT->Hdr, (VOID**)&RT->SetVirtualAddressMap, (VOID**)&gugugugunherereererre30);
    gugugugunherereererre9 = (EFI_CONVERT_POINTER)SetServicePointer(&RT->Hdr, (VOID**)&RT->ConvertPointer, (VOID**)&gugugugunherereererre31);
    gugugugunherereererre10 = (EFI_GET_VARIABLE)SetServicePointer(&RT->Hdr, (VOID**)&RT->GetVariable, (VOID**)&gugugugunherereererre32);
    gugugugunherereererre12 = (EFI_GET_NEXT_VARIABLE_NAME)SetServicePointer(&RT->Hdr, (VOID**)&RT->GetNextVariableName, (VOID**)&gugugugunherereererre33);
    // gugugugunherereererre11 = (EFI_SET_VARIABLE)SetServicePointer(&RT->Hdr, (VOID**)&RT->SetVariable, (VOID**)&HookedSetVariable);
    gugugugunherereererre13 = (EFI_GET_NEXT_HIGH_MONO_COUNT)SetServicePointer(&RT->Hdr, (VOID**)&RT->GetNextHighMonotonicCount, (VOID**)&gugugugunherereererre34);
    gugugugunherereererre14 = (EFI_RESET_SYSTEM)SetServicePointer(&RT->Hdr, (VOID**)&RT->ResetSystem, (VOID**)&gugugugunherereererre35);
    gugugugunherereererre15 = (EFI_UPDATE_CAPSULE)SetServicePointer(&RT->Hdr, (VOID**)&RT->UpdateCapsule, (VOID**)&gugugugunherereererre36);
    gugugugunherereererre16 = (EFI_QUERY_CAPSULE_CAPABILITIES)SetServicePointer(&RT->Hdr, (VOID**)&RT->QueryCapsuleCapabilities, (VOID**)&gugugugunherereererre37);
    gugugugunherereererre17 = (EFI_QUERY_VARIABLE_INFO)SetServicePointer(&RT->Hdr, (VOID**)&RT->QueryVariableInfo, (VOID**)&gugugugunherereererre38);

    // Print confirmation text
    Print(L"\n");
    Print(L"       __ _                                  \n");
    Print(L"  ___ / _(_)___ _ __  ___ _ __  ___ _ _ _  _ \n");
    Print(L" / -_)  _| |___| '  \\/ -_) '  \\/ _ \\ '_| || |\n");
    Print(L" \\___|_| |_|   |_|_|_\\___|_|_|_\\___/_|  \\_, |\n");
    Print(L"                                        |__/ \n");
    Print(L"Made by: Samuel Tulach\n");
    Print(L"Direct Calling By: The CruZ\n");
    Print(L"Thanks to: @Mattiwatti (EfiGuard), Roderick W. Smith (rodsbooks.com)\n\n");
    Print(L"Driver has been loaded successfully. You can now boot to the OS.\n");
    Print(L"If you don't see a blue screen while booting disable Secure Boot!.\n");

    return EFI_SUCCESS;
}
