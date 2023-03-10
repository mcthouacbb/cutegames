#ifndef ENGINE_PROCESS_HPP
#define ENGINE_PROCESS_HPP

#include <boost/process.hpp>
#include <functional>
#include <string>
#include <string_view>
#include "engine.hpp"

class ProcessEngine : public Engine {
   public:
    [[nodiscard]] ProcessEngine(const id_type id, const std::string &path);

    [[nodiscard]] ProcessEngine(const id_type id, const std::string &path, callback_type recv, callback_type send);

    virtual ~ProcessEngine();

    [[nodiscard]] virtual auto is_running() -> bool override;

   protected:
    auto send(const std::string &msg) -> void;

    auto wait_for(const std::string &msg) -> void;

    auto wait_for(const std::string &msg, const callback_type func) -> void;

    auto wait_for(const std::function<bool(const std::string_view msg)> func) -> void;

   private:
    boost::process::opstream m_in;
    boost::process::ipstream m_out;
    boost::process::child m_child;
};

#endif
