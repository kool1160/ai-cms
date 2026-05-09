# AI-CMS — Condition Monitoring System

AI-CMS is a modular condition monitoring system project focused first on a simple outdoor soil moisture prototype.

## V1 Direction

V1 is intentionally small:

- ESP32-based prototype
- One capacitive soil moisture sensor
- Hourly readings
- Local dashboard
- Basic soil status: DRY / WATCH / GOOD / WET
- Simple bar graph display
- Outdoor prototype enclosure notes

## V1 Guardrails

V1 does not include:

- Multiple sensors
- Cloud relay or private cloud dashboard
- AI analytics
- Mobile app
- Agent console
- Raspberry Pi hub
- Matter, Alexa, or Google integration
- Subscriptions or platform features

## Core Principle

Build the foundation first. No NASA version until the basic rocket leaves the pad.

## Project Structure

```text
ai-cms/
├── dashboard/
├── docs/
│   └── v1/
├── firmware/
│   └── esp32-soil-moisture/
└── hardware/
```
