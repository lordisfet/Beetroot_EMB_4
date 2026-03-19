enum State
{
    ON,
    OFF
};

inline State operator!(State s)
{
    return (s == ON) ? OFF : ON;
}