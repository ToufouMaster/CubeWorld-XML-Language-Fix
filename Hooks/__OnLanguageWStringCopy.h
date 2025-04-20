#pragma once

#include "../cwsdk.h"
#include "../cwsdk/cube_funcs.h"
#include <../sqlite/sqlite3.h>
//#include "../cwsdk/msvc_bincompat.h"

void* ASMOnLanguageWStringCopy_jmpback;

sqlite3* db;
std::vector<std::string> file_names = {};
const char* current_lang_file = "";

int last_id = 0;

std::wostream* __fastcall LanguageWStringCopy(std::wostream* stream) {//cube::OptionsWidget* widget) {
    auto gc = cube::GetGameController();
    int id = gc->OptionsWidget->language_id % file_names.size();
    current_lang_file = file_names.at(id).c_str();

    if (id != last_id) {
        // Call function
        typedef cube::Speech* (__fastcall* load_language_t)(cube::Speech* speech);
        load_language_t load_language = (load_language_t)(cube_funcs::instance()->ImageBase + 0xE1970);

        auto base = cube_funcs::instance()->ImageBase;
        auto the_int = (uint32_t)current_lang_file;

        int a = (the_int >> 24) & 0xff;
        int b = (the_int >> 16) & 0xff;
        int c = (the_int >> 8) & 0xff;
        int d = the_int & 0xff;

        WriteBYTE((void*)(base + 0xE1B3F), d);
        WriteBYTE((void*)(base + 0xE1B40), c);
        WriteBYTE((void*)(base + 0xE1B41), b);
        WriteBYTE((void*)(base + 0xE1B42), a);

        load_language(&gc->world.speech);
        last_id = id;
    }
    //stream->write(std::to_wstring(id).c_str(), std::to_wstring(id).size());
    std::wstring wstr = std::wstring(file_names.at(id).begin(), file_names.at(id).end());
    stream->write(wstr.c_str(), wstr.size());
    return stream;
}

void __declspec(naked) ASMOnLanguageWStringCopy() {
    __asm {
        PUSH_ALL

        mov ecx, [ebp - 0x294]
        //mov edx, [ebx + 0x1FC]

        call LanguageWStringCopy

        POP_ALL

        //mov eax, [str]

        jmp[ASMOnLanguageWStringCopy_jmpback];
    }
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::string str = std::string(argv[i]);
        file_names.push_back(str);
    }
    return 0;
}

void SetupOnLanguageWStringCopy() {

    int rc = sqlite3_open("data4.db", &db);
    if (not rc) {
        char* zErrMsg = 0;
        rc = sqlite3_exec(db, "SELECT key FROM blobs", callback, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(zErrMsg);
        }
        sqlite3_close(db);
    }

    auto gc = cube::BusywaitForGameController();
    int id = gc->option_language % file_names.size();
    last_id = id;
    current_lang_file = file_names.at(id).c_str();

    auto base = cube_funcs::instance()->ImageBase;
    WriteBYTE((void*)(base + 0xD369D), 0x90);
    WriteBYTE((void*)(base + 0xD369E), 0x90);
    WriteBYTE((void*)(base + 0xD369F), 0x90);
    WriteBYTE((void*)(base + 0xD36A0), 0x90);
    WriteBYTE((void*)(base + 0xD36A1), 0x90);
    WriteBYTE((void*)(base + 0xD36A2), 0x90);

    WriteBYTE((void*)(base + 0xD36A9), 0x90);
    WriteBYTE((void*)(base + 0xD36AA), 0x90);
    WriteBYTE((void*)(base + 0xD36AB), 0x90);
    WriteBYTE((void*)(base + 0xD36AC), 0x90);
    WriteBYTE((void*)(base + 0xD36AD), 0x90);
    WriteBYTE((void*)(base + 0xD36AE), 0x90);

    //WriteJMP((void*)(base + 0xD36A9), (void*)&ASMOnLanguageWStringCopy);
    WriteCALL((void*)(base + 0xD36A9), (void*)&LanguageWStringCopy);
    WriteBYTE((void*)(base + 0xD36AE), 0x90);

    auto the_int = (uint32_t)current_lang_file;

    int a = (the_int >> 24) & 0xff;  
    int b = (the_int >> 16) & 0xff;  
    int c = (the_int >> 8) & 0xff;  
    int d = the_int & 0xff;

    WriteBYTE((void*)(base + 0xE1B3E), 0x68);
    WriteBYTE((void*)(base + 0xE1B3F), d);
    WriteBYTE((void*)(base + 0xE1B40), c);
    WriteBYTE((void*)(base + 0xE1B41), b);
    WriteBYTE((void*)(base + 0xE1B42), a);
    
    typedef cube::Speech* (__fastcall* load_language_t)(cube::Speech* speech);
    load_language_t load_language = (load_language_t)(cube_funcs::instance()->ImageBase + 0xE1970);
    load_language(&gc->world.speech);

    ASMOnLanguageWStringCopy_jmpback = (void*)(base + 0xD36AF);
}
