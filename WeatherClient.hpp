#ifndef WEATHERCLIENT_HPP
#define WEATHERCLIENT_HPP

#include <string>

class WeatherClient {
public:
    WeatherClient(const std::string& apiKey);
    
    // Fetch raw JSON weather data for a city
    std::string getWeatherData(const std::string& city) const;

private:
    std::string apiKey;
};

#endif // WEATHERCLIENT_HPP
