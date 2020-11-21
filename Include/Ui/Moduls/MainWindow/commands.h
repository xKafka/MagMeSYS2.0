#ifndef COMMANDS_H
#define COMMANDS_H

namespace Commands {

    constexpr unsigned int str2int(const char* str, int h = 0)
    {
        return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
    }

    constexpr unsigned int echo { str2int("echo") };
    constexpr unsigned int move { str2int("move") };
    constexpr unsigned int exit { str2int("exit") };
    constexpr unsigned int close { str2int("close") };

}

#endif // COMMANDS_H
