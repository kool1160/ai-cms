# AI-CMS V2-M4 - App Shell Separation Plan

Status: READY FOR TESTING

Version: V2

## Purpose
Plan the safe separation of the current single-file dashboard into a cleaner V2 app shell without changing runtime behavior.

## Current Starting Point
Current app structure is centered on:
- `dashboard/index.html`
- embedded `<style>` CSS
- embedded dashboard markup
- static/mock moisture/status display content
- static asset references in `dashboard/assets/`

Vite currently builds from the `dashboard/` folder.

## Preserve From V1
Do not change the user-facing V1 behavior/content during shell separation:
- Front Yard Soil Node title/content
- current moisture card structure
- DRY / WATCH / GOOD / WET status display
- active GOOD state example
- recent moisture trend bars
- node health section
- last update / power source display
- soil temperature placeholder-only status
- responsive layout behavior
- current colors, spacing, and visual layout unless Planning opens a UI milestone

## Proposed V2 File Structure
Recommended future shell structure:

```text
dashboard/
  index.html
  src/
    main.js
    data/
      mockNodeData.js
    styles/
      dashboard.css
    components/
      AppShell.js
      Header.js
      MoistureCard.js
      NodeHealthCard.js
      MoistureTrend.js
      StatusExamples.js
  assets/
    favicon-16x16.png
    favicon-32x32.png
    apple-touch-icon.png
    site.webmanifest
    ai-cms-app-icon-192.png
    ai-cms-app-icon-512.png
    logo assets
```

## Separation Targets

### HTML Shell
Keep `dashboard/index.html` as the Vite/static entry shell.

Future target:
- keep document metadata
- keep icon/manifest links
- add controlled script/style references only when implementation begins
- avoid dashboard content changes during the first separation step

### CSS / Styling
Move embedded CSS from `dashboard/index.html` into:
- `dashboard/src/styles/dashboard.css`

Rules:
- preserve all existing selectors first
- no visual redesign
- no spacing/layout changes unless explicitly approved

### Dashboard Content Structure
Move dashboard markup into controlled component-like sections.

Suggested first split:
- `AppShell.js`
- `Header.js`
- `MoistureCard.js`
- `NodeHealthCard.js`
- `MoistureTrend.js`
- `StatusExamples.js`

Rules:
- preserve text/content first
- preserve class names first
- avoid logic expansion

### Status / Data Display Logic
Create a small mock data file only after Planning approves implementation:
- `dashboard/src/data/mockNodeData.js`

Initial data should preserve current values:
- moisture: 42%
- mock ADC: 1724
- status: GOOD
- node: Front Yard Soil Node
- last update: 12 min ago
- power source: USB prototype
- soil temperature: placeholder only

Do not add live sensor connection, cloud, database, or multi-node behavior.

### Graph / Display Sections
Move current bar graph data/markup into a display section.

Preserve current sample values:
- 6 AM: 36%
- 7 AM: 38%
- 8 AM: 41%
- 9 AM: 42%
- 10 AM: 44%
- 11 AM: 42%

No chart library yet.
No dynamic graphing yet.

### Static Assets
Keep all uploaded brand assets in:
- `dashboard/assets/`

Do not rename or regenerate assets unless Planning explicitly approves.

## Do Not Change Yet
Do not change:
- runtime behavior
- UI layout
- visual design
- sensor/status logic
- V1 documentation
- V1 dashboard meaning
- thresholds
- moisture values
- chart/display values
- DS18B20 placeholder status
- app platform scope

Do not add:
- cloud
- multiple nodes
- real sensor polling
- database
- auth
- pH sensor
- camera node
- Matter / Alexa / Google
- subscriptions
- solar power
- Raspberry Pi hub
- native app

## Next Safe Implementation Milestone
Recommended next milestone:

V2-M5 - Static CSS Extraction / No Visual Change

Goal:
- move the embedded CSS from `dashboard/index.html` to `dashboard/src/styles/dashboard.css`
- link the stylesheet from `dashboard/index.html`
- preserve all class names and layout behavior
- make no visual/content/logic changes

Why this first:
- lowest-risk structural improvement
- proves V2 can separate app structure without disturbing V1 behavior
- prepares the dashboard for later shell/component separation

## Exit Criteria For M5
M5 should pass only if:
- dashboard still loads
- visual layout remains unchanged
- icon references still work
- no dashboard content changes
- no sensor/status logic changes
- no V1 reopening or feature drift
