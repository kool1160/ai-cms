const dashboardData = {
  nodeName: 'Front Yard Soil Node',
  eyebrow: 'AI-CMS V1 Local Dashboard',
  subtitle: 'Clean local condition-monitoring app view for the one-sensor V1 prototype.',
  status: 'GOOD',
  connectionStatus: 'Online',
  currentMoisture: 42,
  mockAdcValue: 1724,
  currentMoistureHelper: 'Current estimated soil condition from the Front Yard monitoring point.',
  currentStatusNote: 'GOOD means soil moisture is currently within the target range for this mock node.',
  nodeHealthHelper: 'Quick health snapshot for the local prototype monitoring node.',
  lastUpdate: '12 min ago',
  powerSource: 'USB prototype',
  soilTemperature: '68°F placeholder',
  nodeHealthNote: 'Prototype UI only. No DS18B20 wiring/code, cloud, database, or multi-node connection is active.',
  trendHelper: 'Hourly moisture history showing how soil conditions changed through the morning.',
  trendNote: 'Bars preserve the V1 dashboard graph pattern for the single Front Yard Soil Node.',
  trend: [
    { time: '6 AM', moisture: 36 },
    { time: '7 AM', moisture: 38 },
    { time: '8 AM', moisture: 41 },
    { time: '9 AM', moisture: 42 },
    { time: '10 AM', moisture: 44 },
    { time: '11 AM', moisture: 42 }
  ],
  statusExamplesHelper: 'Simple reference states for the same Front Yard Soil Node.',
  statusExamplesNote: 'These examples stay inside the current V1 application polish scope.',
  statusExamples: [
    { key: 'DRY', className: 'state-dry', text: '18% moisture · needs attention soon.' },
    { key: 'WATCH', className: 'state-watch', text: '29% moisture · getting low, monitor closely.' },
    { key: 'GOOD', className: 'state-good', text: '42% moisture · target range for the prototype.' },
    { key: 'WET', className: 'state-wet', text: '78% moisture · heavily watered or saturated.' }
  ],
  statusOptions: ['DRY', 'WATCH', 'GOOD', 'WET']
};

function setText(selector, value) {
  const element = document.querySelector(selector);
  if (element) element.textContent = value;
}

function renderStatusOptions() {
  const row = document.querySelector('[data-status-options]');
  if (!row) return;

  row.innerHTML = dashboardData.statusOptions
    .map((option) => `<div class="status-chip${option === dashboardData.status ? ' active' : ''}">${option}</div>`)
    .join('');
}

function renderTrend() {
  const bars = document.querySelector('[data-trend-bars]');
  if (!bars) return;

  bars.innerHTML = dashboardData.trend
    .map((item) => `<div class="bar-row"><span>${item.time}</span><div class="bar-track"><div class="bar-fill" style="width:${item.moisture}%"></div></div><span>${item.moisture}%</span></div>`)
    .join('');
}

function renderStatusExamples() {
  const grid = document.querySelector('[data-status-examples]');
  if (!grid) return;

  grid.innerHTML = dashboardData.statusExamples
    .map((item) => `<div class="state-card ${item.className}"><strong>${item.key}</strong><span>${item.text}</span></div>`)
    .join('');
}

function renderDashboard() {
  setText('[data-eyebrow]', dashboardData.eyebrow);
  setText('[data-node-name]', dashboardData.nodeName);
  setText('[data-subtitle]', dashboardData.subtitle);
  setText('[data-chip]', `${dashboardData.status} · ${dashboardData.connectionStatus}`);
  setText('[data-moisture-helper]', dashboardData.currentMoistureHelper);
  setText('[data-moisture-value]', `${dashboardData.currentMoisture}%`);
  setText('[data-adc-value]', `Live moisture reading · Mock ADC value: ${dashboardData.mockAdcValue}`);
  setText('[data-status-note]', dashboardData.currentStatusNote);
  setText('[data-node-health-helper]', dashboardData.nodeHealthHelper);
  setText('[data-connection-status]', dashboardData.connectionStatus);
  setText('[data-last-update]', dashboardData.lastUpdate);
  setText('[data-power-source]', dashboardData.powerSource);
  setText('[data-soil-temperature]', dashboardData.soilTemperature);
  setText('[data-node-health-note]', dashboardData.nodeHealthNote);
  setText('[data-trend-helper]', dashboardData.trendHelper);
  setText('[data-trend-note]', dashboardData.trendNote);
  setText('[data-status-examples-helper]', dashboardData.statusExamplesHelper);
  setText('[data-status-examples-note]', dashboardData.statusExamplesNote);

  renderStatusOptions();
  renderTrend();
  renderStatusExamples();
}

renderDashboard();
