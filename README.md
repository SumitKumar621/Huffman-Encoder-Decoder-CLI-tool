# Huffman Encoder–Decoder CLI tool

A **C++ command-line application** that implements **Huffman Encoding and Decoding** for **lossless text compression** using **priority queues, binary trees, and object-oriented programming**.

---

## 📌 Project Description

This project demonstrates an efficient text compression technique using the **Huffman Coding algorithm**. It assigns variable-length binary codes to characters based on their frequencies, ensuring optimal prefix codes and reduced storage size. The tool also supports decoding to reconstruct the original text.

---

## 🛠️ Technologies Used

- **Language:** C++ (C++17)
- **Core Concepts:**
  - Huffman Coding (Greedy Algorithm)
  - Priority Queue (Min-Heap)
  - Binary Trees
  - Recursion
  - Object-Oriented Programming (OOP)
  - File Handling (`fstream`)
  - Command-Line Interface (CLI)

---

## ✨ Features

- Compresses text using Huffman Encoding
- Decodes compressed data back to original text
- Uses min-heap priority queue for efficient tree construction
- Modular, class-based implementation
- Saves encoded and decoded outputs to files
- CLI-based user interaction

---

## ⚙️ How It Works

1. Accepts text input from the user
2. Builds a frequency table for characters
3. Constructs a Huffman Tree using a priority queue
4. Generates optimal prefix codes
5. Encodes the input text into a binary string
6. Decodes the binary string to verify correctness
7. Saves encoded and decoded results to files
