# AI-CMS V1-M8 — Full Prototype Integration Notes

## Integration Summary

The V1 prototype is integrated as one local ESP32 firmware/dashboard system.

Confirmed integrated pieces:
- One capacitive soil moisture sensor read through ESP32 GPIO 34
- Raw analog moisture readings
- DRY / WATCH / GOOD / WET status logic
- Serial Monitor output
- Local ESP32 web dashboard
- Runtime hourly reading storage
- Recent raw-value bar graph
- Raw value + status history table

## Scope Preserved

The prototype remains one-sensor and local-only.

No redesign was added. Existing working firmware/dashboard pieces were preserved.

## Guardrails Preserved

This integration note does not add:
- Cloud
- Database
- AI analytics
- App/platform features
- Multiple sensors
