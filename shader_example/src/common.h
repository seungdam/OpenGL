#pragma once

#include <memory>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>

std::optional<std::string> LoadTextFile(const std::string& filename);

#define CLASS_PTR(klassName) \
class klassName; \
using klassName ## UPtr = std::unique_ptr<klassName>; \
using klassName ## Ptr = std::shared_ptr<klassName>; \
using klassName ## WPtr = std::weak_ptr<klassName>;

// 사용 예시
// CLASS_PTR(Shader)을 선언하면 
// using ShaderNameUPtr = std::unique_ptr<klassName>; 
// using ShaderNamePtr = std::shared_ptr<klassName>; 
// using ShaderNameWPtr = std::weak_ptr<klassName>;

