float raw2dps(short raw, float dps)
{
    return (((float)raw) / 32768.0) * dps;
}

float raw2gravities(short raw, short gravities)
{
    return (((float)raw) / 32768.0) * gravities;
}

float raw2gauss(short raw, short gauss)
{
    return (((float)raw) / 32768.0) * gauss;
}