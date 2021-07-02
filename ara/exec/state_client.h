#ifndef STATE_CLIENT_H
#define STATE_CLIENT_H

#include <string>
#include <string_view>
#include "../core/result.h"
#include <future>

namespace ara
{
    namespace exec
    {
        class FunctionGroup
        {
        public:
            using CtorToken = std::string;

            FunctionGroup(CtorToken &&token) noexcept;
            ~FunctionGroup() noexcept;
            bool operator==(const FunctionGroup &other) const noexcept;
            bool operator!=(const FunctionGroup &other) const noexcept;

            static ara::core::Result<CtorToken> Preconstruct(
                std::string_view metaModelIdentifier) noexcept;
        };

        class FunctionGroupState
        {
        public:
            using CtorToken = std::string;
            FunctionGroupState(CtorToken &&token) noexcept;
            ~FunctionGroupState() noexcept;
            bool operator==(const FunctionGroupState &other) const noexcept;
            bool operator!=(const FunctionGroupState &other) const noexcept;

            static ara::core::Result<CtorToken> Preconstruct(
                std::string_view metaModelIdentifier) noexcept;
        };

        class StateClient
        {
        public:
        StateClient() noexcept;
        ~StateClient() noexcept;
        std::future<void> SetState(const FunctionGroupState &state);
        std::future<void> GetInitialMachineStateTransitionResult () const noexcept;
        };
    }
}

#endif