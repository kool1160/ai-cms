# AI-CMS V1-M9 — Field Test / Yard Trial

## Goal

Provide simple test guidance for trying the one-sensor ESP32 soil moisture prototype outside in the yard.

## Outdoor Yard Test Steps

1. Place the enclosure in a protected raised location near the test area.
2. Insert the soil moisture sensor into the ground at the target depth.
3. Power the ESP32 and confirm Wi-Fi connection through the Serial Monitor.
4. Open the local dashboard from a device on the same Wi-Fi network.
5. Let the prototype run long enough to capture current readings and at least one stored reading.

## Dry / Wet Soil Observation Notes

Record basic field observations while testing:
- Soil condition: dry, damp, watered, or saturated
- Sensor location: sunny, shaded, sprinkler zone, or garden area
- Raw moisture value shown on dashboard
- Status shown: DRY / WATCH / GOOD / WET
- Whether the displayed status matches what the soil appears to be

## Dashboard Check Steps

Confirm the dashboard shows:
- Current raw moisture value
- Current DRY / WATCH / GOOD / WET status
- Recent reading history
- Recent reading bar graph

Refresh behavior should remain simple and local-only.

## Threshold Adjustment Notes

If readings look wrong:
- Test sensor in dry air and record raw value.
- Test sensor in wet soil and record raw value.
- Compare the dry and wet values against the current thresholds.
- Adjust DRY_THRESHOLD, WATCH_THRESHOLD, and GOOD_THRESHOLD in firmware only after observing real readings.
- Recheck dashboard status after adjustment.

## Guardrails

This field-test plan does not add:
- New features
- Cloud or database storage
- AI analytics
- Multiple sensors
- Hardware redesign
