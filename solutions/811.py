from collections import defaultdict
from typing import List


class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        total_count = defaultdict(int)
        for cpdomain in cpdomains:
            count, domain = cpdomain.split(' ')
            while domain:
                total_count[domain] += int(count)
                domain = domain.partition('.')[2]

        return [f'{count} {domain}' for domain, count in total_count.items()]
