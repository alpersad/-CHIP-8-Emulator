#include <iostream>
#include <cstdint>
#include <fstream>
#include <bitset>
#include <chrono>

using namespace std;

const unsigned int RAM_SIZE = 4096;
const unsigned int START_ADDRESS = 0x200;

class Chip8
{
public:
    uint8_t memory[RAM_SIZE] = {};
    uint8_t vregister[16] = {};
    uint16_t index;
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t program_counter;
    uint8_t stack_pointer;
    uint16_t stack[16] = {};
    uint8_t display[64][32] = {};

    Chip8(char *filename)
    {
        load_rom(filename);
    }

    void load_rom(char *filename)
    {
        // Load ROM into Chip-8 RAM
        streampos size;
        char *memblock;

        ifstream rom("roms/MAZE", ios::in | ios::binary | ios::ate);
        if (rom.is_open())
        {
            size = rom.tellg();
            memblock = new char[size];
            rom.seekg(0, ios::beg);
            rom.read(memblock, size);
            rom.close();

            for (int i = 0; i < size; ++i)
            {
                memory[START_ADDRESS + i] = memblock[i];
            }

            delete[] memblock;
        }
        else
        {
            cout << "ERROR. ROM loading failed" << endl;
        }
    }

    void cycle()
    {
    }

    void decode_opcode(uint16_t opcode)
    {
    }
};

int main(int argc, char *argv[])
{
    cout << "Hello World";
    return 0;
}