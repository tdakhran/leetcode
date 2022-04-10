class Solution:

    def validIPAddress(self, queryIP: str) -> str:

        def isIPv4Chunk(chunk: str) -> bool:
            try:
                digit = int(chunk)
                return 0 <= digit <= 255 and str(digit) == chunk
            except ValueError:
                return False

        def isIPv6Chunk(chunk: str) -> bool:
            try:
                int(chunk, 16)
                return len(chunk) <= 4
            except ValueError:
                return False

        params = {
            'IPv4': {
                'chunks': 4,
                'separator': '.',
                'predicate': isIPv4Chunk
            },
            'IPv6': {
                'chunks': 8,
                'separator': ':',
                'predicate': isIPv6Chunk
            }
        }

        for ip_type, param in params.items():
            chunks = list(
                map(param['predicate'], queryIP.split(param['separator'])))
            if len(chunks) == param['chunks'] and all(chunks):
                return ip_type

        return "Neither"
