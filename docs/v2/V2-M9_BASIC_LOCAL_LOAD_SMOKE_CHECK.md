# AI-CMS V2-M9 - Basic Local Load Smoke Check

Status: READY FOR TESTING

Version: V2

## Purpose
Provide a compact manual smoke check for verifying the V2 dashboard still loads correctly after CSS, data, display logic, and markup separation.

## Manual Smoke Check

Open the dashboard locally or from the deployed/static page.

Check:
- Dashboard opens in browser.
- Page title displays as `AI-CMS | Front Yard Soil Node`.
- CSS loads from `./assets/dashboard.css`.
- Data JS loads from `./assets/dashboard-data.js`.
- Display JS loads from `./assets/dashboard.js`.
- `dashboard-data.js` loads before `dashboard.js`.
- Favicon references do not break page load.
- Apple touch icon reference does not break page load.
- Web manifest reference does not break page load.

## Expected Display Values

Confirm visible values remain:
- Node: `Front Yard Soil Node`
- Header status: `GOOD · Online`
- Moisture: `42%`
- Raw ADC: `1724`
- Connection Status: `Online`
- Last Update: `12 min ago`
- Power Source: `USB prototype`
- Soil Temperature: `68°F placeholder`

## Expected Status / Graph Display

Confirm status row displays:
- DRY
- WATCH
- GOOD active
- WET

Confirm graph values display:
- 6 AM: 36%
- 7 AM: 38%
- 8 AM: 41%
- 9 AM: 42%
- 10 AM: 44%
- 11 AM: 42%

Confirm status examples display:
- DRY: 18% moisture
- WATCH: 29% moisture
- GOOD: 42% moisture
- WET: 78% moisture

## Layout Check

Confirm:
- No obvious broken layout.
- Cards still render with dark dashboard styling.
- Moisture card, node health card, trend section, and status examples section are visible.
- Mobile/tablet/desktop layout does not show obvious clipping, overlap, or horizontal drift.

## Scope Drift Check

Confirm no added scope:
- No cloud.
- No multi-node support.
- No real sensor behavior change.
- No DS18B20 wiring/code.
- No pH/camera/Matter/Alexa/Google/subscriptions/solar/Raspberry Pi/native app work.
- No V1 reopening.

## Pass Criteria

PASS if:
- Dashboard loads.
- CSS/data/display JS references work.
- Values remain unchanged.
- Fallback HTML remains usable if scripts fail.
- No obvious layout or scope drift is found.
