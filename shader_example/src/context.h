#pragma once
#include "common.h"
#include "program.h"

CLASS_PTR(CONTEXT)
class CONTEXT {
public:
    static CONTEXTUPtr Create();
    void Render();
private:
    ProgramUPtr m_program;
    CONTEXT() {};
    bool Init();
    ~CONTEXT();

}