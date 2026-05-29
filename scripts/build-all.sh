#!/bin/bash
# Build all packages (using existing recipes)
cd /mnt/d/rv-port-work/-rv-port-gurleen

RESULTS_FILE="build-results-$(date +%Y%m%d-%H%M%S).csv"
echo "Package,Status,Time" > $RESULTS_FILE

# List of packages that have build scripts
PACKAGES="openblas lapack gsl fftw hdf5"

for PKG in $PACKAGES; do
    echo ""
    echo "=========================================="
    echo "Building $PKG..."
    echo "=========================================="
    
    START=$(date +%s)
    
    if [ -f "packages/$PKG.sh" ]; then
        bash packages/$PKG.sh
        if [ $? -eq 0 ]; then
            STATUS="PASS"
        else
            STATUS="FAIL"
        fi
    else
        echo "⚠️ No build script for $PKG"
        STATUS="SKIP"
    fi
    
    END=$(date +%s)
    DURATION=$((END - START))
    
    echo "$PKG,$STATUS,$DURATION seconds" >> $RESULTS_FILE
done

echo ""
echo "=== BUILD SUMMARY ==="
cat $RESULTS_FILE
