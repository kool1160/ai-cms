# AI-CMS V2-M13 - Dashboard Manual Device Smoke Check

Status: VERIFIED / READY FOR TESTING

Version: V2

## Purpose
Record the real-device/manual smoke check for the V2 dashboard after static file separation.

## Verification Source
Source:
- Chris manual device screenshots provided in chat.
- Device/browser view showed the deployed/local V2 dashboard rendering on a phone-sized screen.

## Manual Checks Recorded

Confirmed from screenshots:
- Dashboard opens.
- CSS loads with dark dashboard styling.
- Moisture card displays.
- Status displays `GOOD`.
- Node Health displays `Online`.
- Raw ADC displays `1724`.
- Recent Moisture Trend graph displays.
- Status examples display.
- No obvious layout break visible on phone-sized view.
- Cards, bars, status buttons, and text remain readable.

Bookmark/app icon:
- Not verified from the provided screenshots.

## Recorded Result
PASS with one note:
- Dashboard device smoke check passed visually.
- Bookmark/app icon home-screen behavior remains not verified in this record.

## Observed Values
Screenshots show expected V2/V1 dashboard values:
- Node: `Front Yard Soil Node`
- Status: `GOOD · Online`
- Moisture: `42%`
- Raw ADC: `1724`
- Connection Status: `Online`
- Last Update: `12 min ago`
- Power Source: `USB prototype`
- Soil Temperature: `68°F placeholder`
- Graph values visible: 36%, 38%, 41%, 42%, 44%, 42%
- Status examples visible: DRY / WATCH / GOOD / WET

## Runtime Changes
No runtime files changed.

## Scope Drift Check
No added scope:
- No UI redesign.
- No layout changes.
- No displayed content changes.
- No sensor behavior changes.
- No cloud.
- No multi-node support.
- No V1 reopening.

## Next Needed
Send this milestone to Testing for lock/reject decision.
