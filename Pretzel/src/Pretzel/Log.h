#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pretzel
{
	class PRETZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}


// core logs macros
#define PZ_CORE_ERROR(...)     ::Pretzel::Log::getCoreLogger()->error(__VA_ARGS__)
#define PZ_CORE_WARN(...)      ::Pretzel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PZ_CORE_INFO(...)      ::Pretzel::Log::getCoreLogger()->info(__VA_ARGS__)
#define PZ_CORE_TRACE(...)     ::Pretzel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define PZ_CORE_FATAl(...)     ::Pretzel::Log::getCoreLogger()->fatal(__VA_ARGS__)


// app logs macros
#define PZ_ERROR(...)	       ::Pretzel::Log::getCoreLogger()->error(__VA_ARGS__)
#define PZ_WARN(...)           ::Pretzel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PZ_INFO(...)           ::Pretzel::Log::getCoreLogger()->info(__VA_ARGS__)
#define PZ_TRACE(...)          ::Pretzel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define PZ_FATAl(...)          ::Pretzel::Log::getCoreLogger()->fatal(__VA_ARGS__)