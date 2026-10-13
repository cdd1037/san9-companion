"""Serialize Win32 .res records without reinterpreting built-in resource types."""
import struct


def identifier(value):
    if isinstance(value, int):
        return struct.pack('<HH', 0xFFFF, value)
    return value.encode('utf-16le') + b'\0\0'


def record(kind, name, language, payload):
    names = identifier(kind) + identifier(name)
    names += b'\0' * (-len(names) % 4)
    metadata = struct.pack('<IHHII', 0, 0x30 if payload else 0, language, 0, 0)
    header_size = 8 + len(names) + len(metadata)
    return (struct.pack('<II', len(payload), header_size) + names + metadata
            + payload + b'\0' * (-len(payload) % 4))


def build_resources(rows, folder):
    output = bytearray(record(0, 0, 0, b''))
    for row in rows:
        kind, name, language = row['keys']
        output.extend(record(kind, name, language, (folder / row['file']).read_bytes()))
    return bytes(output)
