#!/usr/bin/env python3

from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        return len(set(
            [local.replace('.', '').split('+')[0] + '@' + domain
             for local, domain in [email.split('@') for email in emails]]))
