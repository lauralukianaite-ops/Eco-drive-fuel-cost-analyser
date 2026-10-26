# Eco-drive & Fuel Cost Analyser

A desktop application that calculates the most cost-effective travel route based on vehicle fuel consumption, real-time fuel prices, and distance. 

## Key Features
*   **Intuitive User Interface:** Clean, dark-themed GUI built with Qt Creator.
*   **Smart Cost Engine:** Combines vehicle fuel consumption with live distance and fuel prices to sort available routes from cheapest to most expensive.
*   **Live API Integrations:** Utilizes Google Routes API for real-world distances and an OilPriceAPI for live Lithuanian fuel prices (includes a built-in fallback system if offline).
*   **Input Validation:** Ensures safe and accurate data entry before executing API calls.
*   **Local Storage:** Save, load, and manage trip history locally in JSON format.

## Technology Stack
*   **Language:** C++
*   **Framework:** Qt Creator
*   **Data & APIs:** Google Maps API, Fuel Price API, JSON
*   **Version Control:** Git & GitHub

## Getting Started

### Prerequisites
To build and run this project, you will need:
*   Qt Creator / Qt Framework installed.
*   A C++ compiler (e.g., GCC, MSVC).
*   API Keys for Google Routes API and the Fuel Price API.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/lauralukianaite-ops/Eco-drive-fuel-cost-analyser.git
   ```
2. Open the `.pro` or `CMakeLists.txt` file in Qt Creator.
3. Configure your API keys in the relevant configuration file or environment variables.
4. Build and run the project via Qt Creator.

## Future Work
Planned enhancements include integrating a gas station database for on-route refueling, refactoring the architecture, and adding eco-driving tips.

## Team
Developed by **VPK**: Laura Lukianaitė, Urtė Lengvytė, Kamilė Kazevičiūtė.
