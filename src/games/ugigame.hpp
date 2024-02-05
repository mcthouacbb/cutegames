#ifndef UGI_GAME_HPP
#define UGI_GAME_HPP

#include "game.hpp"

class UGIGame : public Game {
   public:
    [[nodiscard]] UGIGame() : Game() {
    }

    [[nodiscard]] UGIGame(const std::string &fen) : Game(fen) {
    }

    virtual ~UGIGame() = default;

    virtual void makemove(const std::string &movestr) override {
        m_move_history.emplace_back(movestr);
    }

    [[nodiscard]] virtual bool is_gameover(std::shared_ptr<Engine> engine) const noexcept override {
        return false;
    }

    [[nodiscard]] virtual auto is_legal_move(const std::string &,
                                             std::shared_ptr<Engine> engine) const noexcept -> bool override {
        return true;
    }

    [[nodiscard]] virtual auto get_result(std::shared_ptr<Engine> engine) const noexcept -> std::string override {
        return "";
    }

   protected:
};

#endif
