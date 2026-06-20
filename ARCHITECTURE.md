# Arduino Home Security System Architecture

## Overview

The Arduino Home Security System consists of four primary layers:

1. **Arduino Sensor Components** – Detect environmental events and send sensor data.
2. **Backend Service (FastAPI)** – Central application that processes sensor events, manages system state, and controls actuators.
3. **Arduino Actuator Components** – Receives events from Backend Service and affects the environment.
4. **React Dashboard** – User interface for monitoring and configuring the system.

The Python Backend application acts as the bridge between the hardware components and the web dashboard.

---

## High-Level Architecture

+------------------------+
|    React Dashboard     |
+------------------------+
          ^
          | REST API
          | WebSocket
          v
+------------------------+
|   Python App (FastAPI) |
+------------------------+
      ^            |
      |            |
 Serial (WIFI)   Serial (WIFI)
      |            v
+-------------+ +-------------+
|   Arduino   | |   Arduino   |
|   Sensors   | |  Actuators  |
+-------------+ +-------------+