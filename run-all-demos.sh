#!/bin/bash
# run-all-demos.sh - Validate all packages
cd /mnt/d/rv-port-work/-rv-port-gurleen

echo "=========================================="
echo "Running all validation demos"
echo "=========================================="

# Run validation script
if [ -f "verify_gurleen_port.py" ]; then
    echo "[1/2] Running verify_gurleen_port.py..."
    python3 verify_gurleen_port.py
    if [ $? -eq 0 ]; then
        echo "✅ Validation passed"
    else
        echo "❌ Validation failed"
        exit 1
    fi
else
    echo "⚠️ verify_gurleen_port.py not found"
fi

# Run audit
if [ -f "automation/audit_engine.py" ]; then
    echo "[2/2] Running audit_engine.py..."
    python3 automation/audit_engine.py
fi

echo "=========================================="
echo "All demos completed"
echo "=========================================="
