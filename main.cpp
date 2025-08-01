#include <iostream>
#include <cstdlib>  // for getenv
#include "WeatherClient.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <city>\n";
        return 1;
    }
    std::string apiKey;
    const char* apiKeyEnv = std::getenv("API_KEY");
    if (!apiKeyEnv) {
        std::cerr << "Error: API_KEY environment variable not set.\n";
        return 1;
    }
    apiKey = apiKeyEnv;
    WeatherClient client(apiKey);

    std::string city = argv[1];

    std::string weatherJson = client.getWeatherData(city);

    if (weatherJson.empty()) {
        std::cout << "Failed to get weather data.\n";
    } else {
        std::cout << "Raw JSON response:\n" << weatherJson << std::endl;
    }

    return 0;
}

