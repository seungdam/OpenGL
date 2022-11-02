#pragma once
#include "common.h"
#include "shader.h"
#include "program.h"

CLASS_PTR(Context);
class Context {
public:
    static ContextUPtr Create();
    void Render();
private:
    ProgramUPtr m_program;
    Context() {};
    bool Init();
};