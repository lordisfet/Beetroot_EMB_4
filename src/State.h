enum State
{
    ON = HIGH,
    OFF = LOW
};

inline State operator!(State s)
{
    return (s == ON) ? OFF : ON;
}