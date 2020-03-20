#ifndef LOOP_H
#define LOOP_H

#include "BaseRule.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace GameSpecification{
    class Loop : public BaseRule{
        public:
            Loop(const std::string& loopType, const std::string& failCondition);

            void process(GameState&) override;
            
        private:
            std::string loopType;
            std::string failCondition;
    };
}
#endif
