function getDashboardData() {
  return typeof dashboardData === 'undefined' ? null : dashboardData;
}

function setText(selector, value) {
  const element = document.querySelector(selector);
  if (element) element.textContent = value;
}

function renderStatusOptions(data) {
  const row = document.querySelector('[data-status-options]');
  if (!row) return;

  row.innerHTML = data.statusOptions
    .map((option) => `<div class="status-chip${option === data.status ? ' active' : ''}">${option}</div>`)
    .join('');
}

function renderTrend(data) {
  const bars = document.querySelector('[data-trend-bars]');
  if (!bars) return;

  bars.innerHTML = data.trend
    .map((item) => `<div class="bar-row"><span>${item.time}</span><div class="bar-track"><div class="bar-fill" style="width:${item.moisture}%"></div></div><span>${item.moisture}%</span></div>`)
    .join('');
}

function renderStatusExamples(data) {
  const grid = document.querySelector('[data-status-examples]');
  if (!grid) return;

  grid.innerHTML = data.statusExamples
    .map((item) => `<div class="state-card ${item.className}"><strong>${item.key}</strong><span>${item.text}</span></div>`)
    .join('');
}

function renderDashboard() {
  const data = getDashboardData();
  if (!data) return;

  setText('[data-eyebrow]', data.eyebrow);
  setText('[data-node-name]', data.nodeName);
  setText('[data-subtitle]', data.subtitle);
  setText('[data-chip]', `${data.status} · ${data.connectionStatus}`);
  setText('[data-source-label]', data.dataSourceLabel);
  setText('[data-moisture-helper]', data.currentMoistureHelper);
  setText('[data-moisture-value]', `${data.currentMoisture}%`);
  setText('[data-adc-value]', `Mock reading · ADC demo value: ${data.mockAdcValue}`);
  setText('[data-status-note]', data.currentStatusNote);
  setText('[data-node-health-helper]', data.nodeHealthHelper);
  setText('[data-connection-status]', data.connectionStatus);
  setText('[data-last-update]', data.lastUpdate);
  setText('[data-power-source]', data.powerSource);
  setText('[data-soil-temperature]', data.soilTemperature);
  setText('[data-node-health-note]', data.nodeHealthNote);
  setText('[data-trend-helper]', data.trendHelper);
  setText('[data-trend-note]', data.trendNote);
  setText('[data-status-examples-helper]', data.statusExamplesHelper);
  setText('[data-status-examples-note]', data.statusExamplesNote);

  renderStatusOptions(data);
  renderTrend(data);
  renderStatusExamples(data);
}

renderDashboard();
