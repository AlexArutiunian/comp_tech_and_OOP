#include <exception>

class Ball {
public:
    Ball() : state(State::Whole) {}

    void destroy() {
        if (state == State::Destroyed) {
            throw std::exception();
        } else if (state == State::Lost) {
            throw std::exception();
        } else {
            state = State::Destroyed;
        }
    }

    void lose() {
        if (state == State::Lost) {
            throw std::exception();
        } else if (state == State::Destroyed) {
            throw std::exception();
        } else {
            state = State::Lost;
        }
    }

private:
    enum class State { Whole, Destroyed, Lost };
    State state;
};
