# Sorting Visualizer 🎨

A C++17 project that visualizes different **sorting algorithms** using **SFML**.  
You can watch in real time how algorithms like **Bubble Sort, Insertion Sort, Selection Sort, Quick Sort** and others operate.

---

## 📦 Requirements

- **CMake >= 3.28**
- **C++17** compatible compiler (e.g., `g++`, `clang`, MSVC)
- Internet connection for CMake to automatically fetch **SFML 3.0.1** via FetchContent

> No manual SFML installation is required — CMake will download it automatically.

---

## ⚙️ Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/MikolajKos/Algorithm-Visualization/
```

 2. Build the project
```bash
cd Algorithm-Visualization
mkdir build
cd build
cmake ..
cmake --build .
```

---

## ▶️ Run the program (from ```Algorithm-Visualization``` directory)

```bash
bin/debug/main.exe
```

---

## 🎮 Usage

1. Start the program. A console menu will appear:
   ```
   Choose algorithm:
   1. Bubble Sort
   2. Insertion Sort
   3. Selection Sort
   4. Quick Sort
   0. Exit
   ```

2. Enter the number corresponding to the algorithm you want to visualize.
3. Watch the bars being swapped and sorted in the SFML window.

---

## 📚 Features

- Real-time visualization of multiple sorting algorithms

- Adjustable number of bars and delay

- Console-based algorithm selection

- Smooth animation with SFML 3.0

---

## 🛠️ Possible Improvements

- Add more algorithms (Heap Sort, Merge Sort, Radix Sort, etc.)

- Swap action counter

- Pause/Resume functionality

- GUI menu for algorithm selection

---

## 📂 Project Structure
```bash
├── includes/
│   ├── Algorithm.hpp    # Sorting algorithms (declarations)
│   └── Visualizer.hpp   # Window & drawing logic
├── src/
│   ├── Algorithm.cpp    # Sorting algorithms (implementations)
│   ├── Visualizer.cpp   # Rendering implementation
│   └── main.cpp         # Program entry point
└── README.md
```
