/**
 * @file ro.h
 * @brief Dynamic module API.
 */

#pragma once

#include <elf.h>
#include <nn/types.h>
#include <nn/util/util_BinTypes.h>

namespace nn {
namespace ro {

namespace detail {
class RoModule {
public:
    RoModule* next;
    RoModule* prev;
    union {
        Elf64_Rel* rel_plt;
        Elf64_Rela* rela_plt;
        void* rel_rela_plt;
    };
    union {
        Elf64_Rel* rel;
        Elf64_Rela* rela;
        void* rel_rela;
    };
    uint8_t* moduleBaseAddr;
    Elf64_Dyn* dynamic;
    bool is_rela;
    uint8_t pad_x31[7];
    Elf64_Xword plt_size;
    void (*initFunc)();
    void (*finiFunc)();
    Elf64_Word* hashBucket;
    Elf64_Word* hashChain;
    char* dynstrTable;
    Elf64_Sym* dynsymTable;
    Elf64_Xword dynstrTable_size;
    void** got_plt;
    Elf64_Xword rela_dyn_size;
    Elf64_Xword rel_dyn_size;
    Elf64_Xword relEnt_count;
    Elf64_Xword relaEnt_count;
    Elf64_Xword nchain;
    Elf64_Xword nbucket;
    Elf64_Xword off_soname;
    uint64_t unk_xb8;
    bool unk_xc0;
    uint8_t pad_xc1[7];
    Elf64_Xword ArchitectureData;

    void Initialize(uint8_t* moduleBaseAddr, uint64_t arg1_0, Elf64_Dyn* dynamic, bool arg4_0);
    Elf64_Sym* Lookup(const char* symbol);
    void Relocation(bool lazyGotPlt);
    void CallInit();
    void CallFini();
    bool ResolveSym(Elf64_Addr* symbolAddr, Elf64_Sym* symbol);
};

static_assert(sizeof(RoModule) == 0xD0, "RoModule definition!");
}  // namespace detail

class Module {
public:
    detail::RoModule* ModuleObject;
    uint32_t State;
    void* NroPtr;
    void* BssPtr;
    void* _x20;
    void* SourceBuffer;
    char Name[256]; /* Created by retype action */
    uint8_t _x130;
    uint8_t _x131;
    bool isLoaded;  // bool
};

struct ModuleId {
    uint8_t build_id[0x20];
};

struct NroHeader {
    static constexpr uint32_t NroMagic = util::MakeSignature('N', 'R', 'O', '0');

    uint32_t entrypoint_insn;
    uint32_t mod_offset;
    uint8_t _x8[0x8];
    uint32_t magic;
    uint8_t _x14[0x4];
    uint32_t size;
    uint8_t _x1c[0x4];
    uint32_t text_offset;
    uint32_t text_size;
    uint32_t ro_offset;
    uint32_t ro_size;
    uint32_t rw_offset;
    uint32_t rw_size;
    uint32_t bss_size;
    uint8_t _x3c[0x4];
    ModuleId module_id;
    uint8_t _x60[0x20];
};
static_assert(sizeof(NroHeader) == 0x80, "NroHeader definition!");

struct ProgramId {
    uint64_t value;

    inline explicit operator uint64_t() const { return this->value; }
};

struct NrrCertification {
    uint64_t programID_Mask;
    uint64_t programID_Pattern;
    uint8_t reserved_x10[0x10];

    uint8_t modulus[0x100];
    uint8_t signature[0x100];
};
static_assert(sizeof(NrrCertification) == 0x220, "NrrCertification definition!");

enum NrrKind : uint8_t {
    NrrKind_User = 0,
    NrrKind_JitPlugin = 1,
    NrrKind_Count,
};

struct NrrHeader {
    static constexpr uint32_t NrrMagic = util::MakeSignature('N', 'R', 'R', '0');

    uint32_t magic;
    uint8_t _x4[0xC];
    NrrCertification certiicate;
    uint8_t nrr_signature[0x100];
    ProgramId program_id;
    uint32_t size;
    NrrKind type; /* 7.0.0+ */
    uint8_t _x33d[3];
    uint32_t hashes_offset;
    uint32_t num_hashes;
    uint8_t _x348[8];
};
static_assert(sizeof(NrrHeader) == 0x350, "NrrHeader definition!");

struct RegistrationInfo {
    enum State {
        State_Unregistered,
        State_Registered,
    };
    State state;
    NrrHeader* nrrPtr;
    uint64_t _x10;
    uint64_t _x18;
};

enum BindFlag {
    BindFlag_Now = 1,
    BindFlag_Lazy = 2,
};

Result Initialize();
Result InitializeWithPortName(const char* portname);  // "ldr:ro" or "ro:1"
Result Finalize();

Result GetBufferSize(uint64_t* size, const void* nro);  // Gets Bss size from nro+0x38

Result RegisterModuleInfo(nn::ro::RegistrationInfo* regInfo, const void* nrr);
Result RegisterModuleInfo(nn::ro::RegistrationInfo* regInfo, const void* nrr, uint32_t);
Result UnregisterModuleInfo(nn::ro::RegistrationInfo* regInfo);

Result LoadModule(Module* outModule, const void* nro, void* nroBss, uint64_t nroBssSize, int32_t flags);
Result LoadModule(Module* outModule, const void* nro, void* nroBss, uint64_t nroBssSize, int32_t flags,
                  bool);
Result UnloadModule(Module* module);

Result LookupSymbol(uint64_t* funcAddress, const char* symbolName);
Result LookupModuleSymbol(uint64_t* funcAddress, const Module* module, const char* symbolName);
}  // namespace ro

}  // namespace nn
