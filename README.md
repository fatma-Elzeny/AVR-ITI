# AVR Drivers Architecture

This repository contains modular and reusable drivers for AVR microcontrollers. The drivers are organized into several layers and modules to ensure scalability and maintainability.

---

## File Structure


---

## Layers Description

### 1. **Hardware Abstraction Layer (HAL)**

The HAL layer contains high-level drivers that interact with external hardware components, such as switches and LEDs. Each module in this layer is designed with configuration files to allow easy adaptation for various hardware designs.

- **SWITCH Module**:
  - `SWITCH.c` and `SWITCH.h`: Core logic for switch initialization and state management.
  - `SWITCH_CFG.c` and `SWITCH_CFG.h`: Pin and port configurations for the switches.

- **LED Module**:
  - `LED.c` and `LED.h`: Functions to control LEDs (e.g., turning them on/off, toggling).
  - `LED_CFG.c` and `LED_CFG.h`: Configuration files for LED pins.

### 2. **Microcontroller Abstraction Layer (MCAL)**

The MCAL layer includes drivers that provide a direct interface to the AVR hardware peripherals.

- **MDIO Module**:
  - Provides APIs for digital input/output pin operations (read, write, toggle).

- **MPORT Module**:
  - Manages pin direction and mode (e.g., input, output, pull-up).

### 3. **Library (LIB)**

This layer includes utility headers that provide common macros and type definitions used throughout the drivers.

- `BIT_MATH.h`: Contains macros for bitwise operations like `SET_BIT`, `CLR_BIT`, `TOG_BIT`.
- `STD_TYPES.h`: Defines standard data types such as `u8`, `s16`, `f32`.

---



