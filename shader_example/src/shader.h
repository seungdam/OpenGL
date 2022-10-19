#pragma once
#include "common.h"

CLASS_PTR(Shader);
class Shader {
public:
    static ShaderUPtr CreateFromFile(const std::string& filename,GLenum shaderType);
    // 무조건 이 함수를 통해서만 쉐이더를 생성할 수 있도록 한다.
    ~Shader() {if(m_shader) glDeleteShader(m_shader)};
    uint32_t Get() const { return m_shader; }    
private:
    Shader() {} // 생성자가 private이기에 외부에서 부를 수 없다. Shader shader X
    bool LoadFile(const std::string& filename, GLenum shaderType);
    uint32_t m_shader { 0 };  // shader id를 저장할 멤버
};