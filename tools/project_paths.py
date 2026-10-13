"""Canonical locations for the current workspace and recovery inputs."""
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = PROJECT_ROOT / 'src'
RECOVERY_ROOT = PROJECT_ROOT / 'recovery'
ASSETS_ROOT = PROJECT_ROOT / 'assets'
BUILD_ROOT = PROJECT_ROOT / 'build'
OUTPUT_ROOT = PROJECT_ROOT / 'out'
TEST_ROOT = PROJECT_ROOT / 'tests'
