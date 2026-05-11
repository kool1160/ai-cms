# AI-CMS V2-M11 - Midpoint Source-of-Truth Update

Status: READY FOR TESTING

Version: V2

## Purpose
Record the V2 midpoint source of truth after completed milestones V2-M1 through V2-M10.

## Current V2 State
AI-CMS V2 is a controlled software/app shell structure lane built around the completed V1 local soil-monitoring dashboard.

V2 has separated the original single-file dashboard into cleaner static parts while preserving V1 behavior, layout, and displayed values.

## Completed / Locked Milestone Summary

### V2-M1 - Project Shell / Source-of-Truth Setup
- Started V2 as a new controlled version lane.
- Preserved V1 as LOCKED / PASSED / COMPLETE.
- Set V2 milestone cap to 20.
- Confirmed V2 starts with software/app shell/system structure work.

### V2-M2A - Manual Brand Asset Upload Verification
- Verified manually uploaded AI-CMS brand assets in `dashboard/assets/`.
- Confirmed app/bookmark icons, Apple touch icon, favicons, and manifest assets.
- Corrected manifest icon paths for local asset resolution.

### V2-M2B - Dashboard Icon Reference Wiring
- Wired favicon, Apple touch icon, and manifest references into `dashboard/index.html`.
- Used existing assets only.
- No UI redesign or runtime scope change.

### V2-M3 - Current App Structure Audit / Safe Change Map
- Documented current app structure.
- Identified `package.json`, `dashboard/index.html`, `dashboard/assets/`, `docs/v1/`, and `docs/v2/` structure.
- Marked V1-complete references and safe V2 candidates.

### V2-M4 - App Shell Separation Plan
- Planned safe separation of the single-file dashboard.
- Defined future targets for HTML shell, CSS, static data, display logic, graph/status sections, and assets.
- Recommended CSS extraction as the next safe implementation step.

### V2-M5 - Static CSS Extraction / No Visual Change
- Created `dashboard/assets/dashboard.css`.
- Moved embedded CSS out of `dashboard/index.html`.
- Preserved dashboard visuals and layout.

### V2-M6 - Static Data Extraction / No Behavior Change
- Created `dashboard/assets/dashboard-data.js`.
- Moved static/mock dashboard data into the data file.
- Preserved displayed values and fallback HTML.

### V2-M7 - Static Display Logic Extraction / No Behavior Change
- Created `dashboard/assets/dashboard.js`.
- Moved display/update render logic into the display JS file.
- Reduced `dashboard-data.js` to data-only.
- Preserved fallback HTML behavior.

### V2-M8 - Dashboard Section Markup Cleanup / No Visual Change
- Added maintainability comments, semantic labels, and section classes in `dashboard/index.html`.
- Preserved data hooks, fallback values, layout, and display behavior.

### V2-M9 - Basic Local Load Smoke Check Documentation
- Created manual smoke-check checklist.
- Covered CSS, data JS, display JS, icons, manifest, displayed values, graph/status examples, layout, and scope drift.

### V2-M10 - Manual Browser Smoke Check Execution
- Created smoke-check result record.
- Completed repo-level reference checks.
- Marked live browser execution as not runnable through the current tool path.
- Confirmed fallback values and file references remain present.

## Current Dashboard Structure

Current runtime structure:

```text
dashboard/
  index.html
  assets/
    dashboard.css
    dashboard-data.js
    dashboard.js
    favicon-16x16.png
    favicon-32x32.png
    apple-touch-icon.png
    site.webmanifest
    ai-cms-app-icon-192.png
    ai-cms-app-icon-512.png
    logo / brand assets
```

## Current Runtime Roles

### `dashboard/index.html`
- Main dashboard HTML shell.
- Contains fallback HTML content.
- References CSS, static data JS, display JS, icons, and manifest.
- Preserves current visible dashboard structure.

### `dashboard/assets/dashboard.css`
- Contains dashboard styling.
- Extracted from original embedded `<style>` block.
- No visual redesign intended.

### `dashboard/assets/dashboard-data.js`
- Static/mock V1 dashboard data.
- Holds values for node name, moisture, status, ADC, node health, trend graph, and status examples.

### `dashboard/assets/dashboard.js`
- Static display/update render logic.
- Reads `dashboardData` and updates matching data hooks.
- Leaves fallback HTML usable if data/display script does not run.

### `dashboard/assets/`
- Brand assets, icons, favicons, Apple touch icon, and manifest.

## Preserved Display Values
Current V2 still preserves V1 displayed values:
- Node: `Front Yard Soil Node`
- Status: `GOOD`
- Header: `GOOD · Online`
- Moisture: `42%`
- Raw ADC: `1724`
- Connection: `Online`
- Last Update: `12 min ago`
- Power Source: `USB prototype`
- Soil Temperature: `68°F placeholder`
- Graph values: 36%, 38%, 41%, 42%, 44%, 42%
- Status examples: DRY / WATCH / GOOD / WET

## Locked Rules
V1 remains closed unless Chris explicitly opens a controlled V1 add-on.

Do not add unless Planning explicitly approves:
- cloud
- multi-node support
- real sensor integration changes
- DS18B20 wiring/code
- pH sensor
- camera node
- Matter integration
- Alexa / Google integration
- subscriptions
- solar power
- Raspberry Pi hub
- native app
- platform expansion

Case/enclosure work remains separate.

## Next Safe Implementation Lane
Recommended next lane after M11:

V2-M12 - Dashboard Runtime Structure Check / Static File Reference QA

Goal:
- verify current split-file runtime structure
- confirm `index.html` references all expected static files
- confirm fallback HTML and JS-rendered values align
- document any cleanup needed before deeper component/app shell work

Why this next:
- V2 has now separated CSS, data, and display logic.
- Before more structure work, the static runtime should be checked and locked.
- This keeps V2 controlled and avoids drifting into cloud, live sensor, or platform work.

## Midpoint Conclusion
V2 midpoint is stable as a structured static dashboard lane. The project has improved maintainability without changing V1 dashboard behavior, displayed values, or scope.
