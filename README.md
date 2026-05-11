# Math Graph C++

An interactive mathematical function visualizer written in C++ using the **raylib** library. The application allows you to draw graphs based on user-defined formulas in real time and provides full navigation within the coordinate system.

The project also includes a separate custom library called **StoneMath**, which acts as a parser and evaluator for mathematical expressions (built using a Lexer and Parser).

## ✨ Main Features

* **Dynamic rendering:** The graph updates automatically within a fraction of a second after entering or modifying a function in the input field (e.g., `y = sin(x)`).
* **Interactive navigation (Camera):**

    * Panning the graph in all directions.
    * Smooth zooming in and out with proper grid scaling.
* **Custom math engine (`StoneMath`):** A built-in lexical and syntax analyzer that transforms input text (string) into executable mathematical functions.
* **Analytical interface:** Real-time display of FPS and precise mouse coordinates within the coordinate system.

## 🛠️ Technologies and Architecture

* **Language:** C++
* **Graphics and UI:** raylib
* **Build system:** CMake
* **Internal dependencies:** `StoneMath` module (Lexer, Parser, Evaluator) located in the `libs/` directory.

## 📂 Project Structure

```text
math-graph-cpp/
├── CMakeLists.txt              # Main project build configuration
├── CoordinateSystem.cpp / .h   # Logic for rendering axes, grid, and graphs
├── Point.cpp / .h              # Helper structures for geometry
├── main.cpp                    # Main application loop and raylib integration
└── libs/
    └── StoneMath/              # Math evaluation library
        ├── CMakeLists.txt      # Separate configuration file for the library
        └── src/
            ├── Lexer.cpp       # Tokenization of expressions (e.g. 'sin', '(', 'x', ')')
            ├── Parser.cpp      # Building the syntax tree (AST)
            ├── Evaluator.cpp   # Computing final values for X
            └── StoneMath.cpp   # Main API of the library
```

## 🚀 Build and Run

Since the project uses CMake, the build process is standardized.

### Prerequisites:

* A compiler supporting C++17 or newer (GCC, Clang, MSVC).
* CMake installed.
* raylib library (either installed in the system or automatically fetched by CMake).

### Build Steps:

1. Clone the repository:

   ```bash
   git clone <url-twojego-repozytorium>
   cd math-graph-cpp
   ```

2. Create a build directory and navigate into it:

   ```bash
   mkdir build && cd build
   ```

3. Run CMake and build the project:

   ```bash
   cmake ..
   cmake --build .
   ```

4. Run the application:

   ```bash
   ./math-graph-cpp
   ```

## 📄 License

This project is licensed under the MIT License.
You are free to use, modify, and distribute this software in accordance with the terms of the MIT license.
