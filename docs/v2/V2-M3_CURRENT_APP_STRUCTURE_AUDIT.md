# AI-CMS V2-M3 - Current App Structure Audit / Safe Change Map

Status: READY FOR TESTING

Version: V2

## Current App Entry
- `package.json`
  - Vite project scripts live here.
  - Current build command: `vite build dashboard --outDir ../dist`.
  - Current app source entry is the `dashboard/` folder.

## Dashboard / UI Files
- `dashboard/index.html`
  - Main dashboard HTML.
  - Contains the V1 local dashboard content.
  - Contains embedded CSS in the `<style>` block.
  - Contains static icon references wired to `dashboard/assets/`.

## Sensor / Data / Status Logic
Current sensor/data/status behavior is embedded in `dashboard/index.html` as static/mock dashboard content.

Known current UI/status content:
- Front Yard Soil Node
- moisture reading
- DRY / WATCH / GOOD / WET status examples
- recent moisture trend bars
- node health
- last update
- power source
- soil temperature placeholder only

No separate sensor/data/status logic file was identified in the reviewed structure.

## Styling / Global CSS
- Styling is currently embedded inside `dashboard/index.html`.
- No separate global CSS file was identified in the reviewed structure.

## Brand / Static Assets
- `dashboard/assets/`
  - app/bookmark icons
  - Apple touch icon
  - favicon PNGs
  - web manifest
  - logo/brand assets uploaded manually by Chris

## Documentation Structure
- `docs/v1/`
  - V1 completion and source-of-truth documentation.
  - Treat as V1-complete reference material.

- `docs/v2/`
  - V2 source-of-truth and milestone documentation.
  - V2-M1 established V2 as a controlled version lane.
  - V2-M3 records this app structure audit before runtime changes begin.

## Protect As V1-Complete Reference
Do not change unless Planning explicitly approves:
- `docs/v1/`
- V1 hardware validation records
- V1 completion/source-of-truth records
- V1 dashboard behavior/content in `dashboard/index.html`
- DRY / WATCH / GOOD / WET baseline logic and examples
- soil temperature placeholder status

## Safe Candidates For V2 App Shell Work
Safe only when Planning opens a controlled milestone:
- create new V2 app shell files
- split embedded CSS into a controlled stylesheet
- split dashboard sections into structured components/modules
- create a V2 structure around the existing dashboard without changing V1 behavior
- add documentation in `docs/v2/`

## Guardrails
Do not add unless explicitly approved:
- cloud
- multiple nodes
- pH sensor
- camera node
- Matter integration
- Alexa / Google integration
- subscriptions
- solar power
- Raspberry Pi hub
- native mobile app
- DS18B20 wiring / code
- V1 dashboard behavior changes

## Current Conclusion
The current app is a compact Vite/static dashboard structure centered on `dashboard/index.html`. V2 runtime work should begin by creating controlled structure around the existing dashboard, not by rewriting V1 behavior.
