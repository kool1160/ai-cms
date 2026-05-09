# AI-CMS V1-M7 — Outdoor Prototype Enclosure Plan

## Purpose

Document practical outdoor enclosure notes for the first ESP32 soil moisture prototype.

## Enclosure Type / Size Guidance

Use a small outdoor-rated plastic project box large enough to hold the ESP32, wiring slack, and simple mounting support without crowding the board.

Recommended prototype target:
- Weather-resistant plastic enclosure
- Clear or removable lid preferred for inspection
- Enough depth for ESP32 clearance and wire bend radius
- Room for foam tape, standoffs, or a small internal mounting plate

This is prototype guidance only, not a production enclosure design.

## ESP32 + Wiring Placement

- Mount the ESP32 inside the enclosure above the bottom surface when practical.
- Keep wiring organized with light slack so the board is not pulled by the sensor lead.
- Avoid placing the ESP32 directly against any location where water could collect.
- Keep the USB/programming side accessible if possible.

## Sensor Lead Exit / Weather Sealing

- Route the soil moisture sensor lead through a small drilled exit hole near the lower side of the box.
- Seal around the wire exit with silicone or similar removable weather sealant for prototype use.
- Use a drip loop outside the enclosure so water does not run directly into the wire opening.
- Do not require waterproof bulkhead connectors for V1 prototype scope.

## Mounting / Strain Relief Basics

- Mount the enclosure to a stake, post, fence edge, or protected raised location near the sensor area.
- Add simple strain relief inside the box using a zip tie, adhesive mount, or clamp point.
- Keep the sensor cable from carrying the weight of the box.
- Position the box high enough to reduce splash exposure from rain or sprinklers.

## Guardrails

This milestone does not include:
- Solar power
- Battery system design
- PCB design
- Required waterproof connectors
- Cloud, app, AI, or platform features
