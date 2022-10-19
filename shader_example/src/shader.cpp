#include "shader.h"

Shader::CreateFromFile(const std::string& filename,GLenum shaderType) {
    auto shader = ShaderUPtr{new Shader()}; // shader 클래스 안 이기 때문에 여기서는 생성 가능.
    if(!shader->LoadFile(filename,shaderType)) return nullptr; // 파일 로드 실패시 null 반환
    return std::move(shader); // 생성 성공시 쉐이더의 주도권을 외부로 옮긴다.
}

bool Shader::LoadFile(const std::string& filename, GLenum shaderType) {
    auto result = LoadTextFile(filename); // file loaading
    if (!result.has_value()) // 값이 있는지 없는지 체크 optional<std::string>
    return false;

    auto& code = result.value(); // file size가 클 수 도 있으니 &로 받는다.
    const char* codePtr = code.c_str();
    int32_t codeLength = (int32_t)code.length();

    // 쉐이더를 하나 생성한다.
    m_shader = glCreateShader(shaderType); // 핸들 생성
    glShaderSource(m_shader, 1, (const GLchar* const*)&codePtr, &codeLength); // 로드한 코드를 쉐이더에 집어 넣는다.
    glCompileShader(m_shader); // 쉐이더 컴파일

    int success = 0;
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success); // 쉐이더의 정보를 얻어온다.
    if (!success) { //쉐이더 컴파일 실패했을 경우
        char infoLog[1024];
        glGetShaderInfoLog(m_shader, 1024, nullptr, infoLog);
        SPDLOG_ERROR("failed to compile shader: \"{}\"", filename);
        SPDLOG_ERROR("reason: {}", infoLog);
        return false;
    }
    return true;
}