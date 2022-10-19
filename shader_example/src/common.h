#pragma once

#include <memory>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <spdlog/spdlog.h>

std::optional<std::string> LoadTextFile(const std::string& filename);

