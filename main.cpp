#include <iostream>
#include "WeatherClient.hpp"

int main() {
    std::string apiKey = "YOUR_API_KEY"; // Replace with your API key
    WeatherClient client(apiKey);

    std::cout << "Enter city: ";
    std::string city;
    std::getline(std::cin, city);

    std::string weatherJson = client.getWeatherData(city);

    if (weatherJson.empty()) {
        std::cout << "Failed to get weather data.\n";
    } else {
        std::cout << "Raw JSON response:\n" << weatherJson << std::endl;
    }

    return 0;
}
