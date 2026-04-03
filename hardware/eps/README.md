# 🛰️ CubeSat EPS Component Test Repository

This repo is structured to help you track, test, and validate individual electrical and power system components for your CubeSat projects.

## 📁 Directory Structure

```plaintext
cubesat-eps-tests/
├── README.md
├── templates/
│   └── test-plan-template.md
├── components/
│   ├── LTC4162/
│   │   └── test-plan.md
│   ├── TPSM5D1806/
│   │   └── test-plan.md
│   ├── SM141K10TF/
│   │   └── test-plan.md
│   └── DummyLoad150W/
│       └── test-plan.md
└── assets/
    ├── photos/
    └── data-logs/
```

Each `components/<name>/test-plan.md` file holds an individual test plan.
Place any oscilloscope screenshots, wiring photos, or CSV logs into `assets/` for reference and linking.

---

## 📄 templates/test-plan-template.md

```markdown
# 📦 Component Test Plan: [Component Name]

## 🔍 Objective
- What is the purpose of testing this component?
- What are you trying to validate or learn?

## ⚙️ Test Setup
- Input connections
- Output connections
- Instrumentation (scope, multimeter, dummy load, etc.)
- Load conditions (e.g., 1A, 3.3V)

## 🧪 Test Steps
1. Power the component with [voltage range]
2. Measure output at [expected conditions]
3. Vary the load and record voltage stability
4. Observe thermal behavior
5. Log any abnormal conditions

## 📏 Measurements
- Input voltage and current
- Output voltage and current
- Efficiency (% if measurable)
- Voltage ripple and transient response

## 🧠 Learnings / Observations
- How well does it meet the expected performance?
- Any thermal limitations or instability?
- Is it suitable for the CubeSat mission phase you’re targeting?

## ⚠️ Safety Notes
- Include inline fuse or overvoltage protection?
- Reverse polarity protection?
- Cell balancing or thermistor needed?
```

---

Would you like me to zip this up for you or help you create a VS Code workspace with preloaded notes and tasks next?
