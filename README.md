# Apexchange

Apexchange is an experimental **high-performance trading exchange engine** written in modern C++.  
The goal of the project is to explore the architecture and implementation of **low-latency, high-throughput order matching systems**, similar to those used in financial exchanges.

The project focuses on:

- deterministic execution
- low latency data structures
- lock-free / low contention concurrency
- high throughput order matching
- hardware-aware performance optimisation

Although initially targeting **digital asset markets**, the architecture is designed to be **asset-agnostic** and applicable to traditional financial markets.

This project also serves as a platform for experimenting with **systems programming, performance engineering, and exchange design**.

---

# Design Goals

- **Low latency**
- **High throughput**
- **Deterministic behaviour**
- **Minimal allocations in hot paths**
- **Cache-friendly data structures**
- **Clear separation between market data, matching engine, and networking layers**

---

# Current Status

Early development.

The first milestone is implementing the **core order book and matching engine**.

---

# Roadmap

## Phase 1 — Core Matching Engine

### Order Book

Implement a high-performance limit order book supporting:

- bid/ask price levels
- price-time priority
- limit orders
- market orders
- order cancellation
- order modification

Tasks:

- [ ] Define core order types
- [ ] Define price level structure
- [ ] Implement order storage
- [ ] Implement order insertion
- [ ] Implement order cancellation
- [ ] Implement order modification
- [ ] Implement matching logic
- [ ] Implement trade generation
- [ ] Unit tests for matching correctness

Possible data structure experiments:

- intrusive linked lists
- price level arrays
- red-black trees / maps
- flat price indexed structures

---

## Phase 2 — Matching Engine Infrastructure

- [ ] Order ID generation
- [ ] Timestamping
- [ ] Trade event structures
- [ ] Market data event generation
- [ ] Replay / deterministic testing

---

## Phase 3 — Market Data

- [ ] Order book snapshot generation
- [ ] Incremental book updates
- [ ] Trade stream
- [ ] Market data feed API

---

## Phase 4 — Performance

- [ ] Benchmark harness
- [ ] Latency measurement
- [ ] Throughput benchmarking
- [ ] Memory profiling
- [ ] Cache analysis

Target:

- millions of orders per second
- microsecond level latency

---

## Phase 5 — Networking

- [ ] Client gateway
- [ ] order entry protocol
- [ ] market data protocol
- [ ] session management

Possible technologies:

- TCP
- UDP multicast
- binary protocol

---

## Phase 6 — Multi-Threaded Architecture

- [ ] lock-free queues
- [ ] gateway → engine pipeline
- [ ] market data fan-out
- [ ] NUMA aware design

---

## Phase 7 — Exchange Simulation

- [ ] matching engine simulation
- [ ] market replay
- [ ] stress testing

---

# Technologies

- C++20 / C++23
- modern CMake
- unit testing framework (TBD)
- benchmarking tools

---

# Long Term Goals

- highly optimised matching engine
- realistic exchange architecture
- reproducible benchmarking environment
- experimentation platform for low-latency systems design

---

# License

TBD