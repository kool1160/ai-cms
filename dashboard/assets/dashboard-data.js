const dashboardData = {
  dataSourceLabel: 'Demo Data',
  nodeName: 'Front Yard Soil Node',
  eyebrow: 'AI-CMS V1 Local Dashboard',
  subtitle: 'Demo app view using mock/fallback values for the one-sensor V1 prototype.',
  status: 'GOOD',
  connectionStatus: 'Online',
  currentMoisture: 42,
  mockAdcValue: 1724,
  currentMoistureHelper: 'Mock reading shown for UI/demo verification. Live ESP32 values should be clearly labeled when connected.',
  currentStatusNote: 'GOOD is currently shown from demo data, not a confirmed live ESP32 reading.',
  nodeHealthHelper: 'Demo node health shown for app verification. Live Node should be used only when a real ESP32 source is active.',
  lastUpdate: '12 min ago',
  powerSource: 'USB prototype',
  soilTemperature: '68°F placeholder',
  nodeHealthNote: 'Demo/fallback UI only. No DS18B20 wiring/code, cloud, database, or multi-node connection is active.',
  trendHelper: 'Mock hourly moisture history for dashboard display verification.',
  trendNote: 'Demo trend bars preserve the V1 dashboard graph pattern for the single Front Yard Soil Node.',
  trend: [
    { time: '6 AM', moisture: 36 },
    { time: '7 AM', moisture: 38 },
    { time: '8 AM', moisture: 41 },
    { time: '9 AM', moisture: 42 },
    { time: '10 AM', moisture: 44 },
    { time: '11 AM', moisture: 42 }
  ],
  statusExamplesHelper: 'Demo reference states for the same Front Yard Soil Node.',
  statusExamplesNote: 'These examples are demo labels only and are not active live sensor readings.',
  statusExamples: [
    { key: 'DRY', className: 'state-dry', text: '18% demo moisture · needs attention soon.' },
    { key: 'WATCH', className: 'state-watch', text: '29% demo moisture · getting low, monitor closely.' },
    { key: 'GOOD', className: 'state-good', text: '42% demo moisture · target range for the prototype.' },
    { key: 'WET', className: 'state-wet', text: '78% demo moisture · heavily watered or saturated.' }
  ],
  statusOptions: ['DRY', 'WATCH', 'GOOD', 'WET']
};
