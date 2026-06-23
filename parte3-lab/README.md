# Part 3.A - Corporate Cyber Range & Lab Deployment

This section documents the successful provisioning and deployment of the automated corporate lab infrastructure designed to simulate a multi-tiered segmented network environment.

## 1. Deployment Verification
The containerized network architecture was initialized via Docker Compose. The environment status was audited using the native platform test suite:

```bash
sudo make test
```

* **System Response:** `Lab is up.` 
This output confirms that all 8 decoupled microservices and isolated virtual routing switches are operational and correctly bound to their designated networks.

## 2. Network Topology & Architecture Matrix

The infrastructure enforces strict network segmentation into two primary security boundaries: the **Public Subnet** (accessible from external vectors) and the **Corporate Subnet** (air-gapped backend database and services).

| Container Hostname | Public Network (IP) | Corporate Network (IP) | Infrastructure Role |
| :--- | :--- | :--- | :--- |
| **p-web-01** | 172.16.10.10 | - | Primary Public Web Server (Primary Target) |
| **p-web-02** | 172.16.10.11 | - | Auxiliary Support Web Node |
| **p-ftp-01** | 172.16.10.20 | - | Corporate Public File Transfer Protocol (FTP) Server |
| **c-db-01** | - | 10.1.0.10 | Internal Relational Database Management System (Air-gapped) |
| **c-mail-01** | - | 10.1.0.20 | Secure Internal Corporate Mail Gateway |

* **Validated Network Interfaces:** 
  * `br_public` (Subnet Range: 172.16.10.0/24)
  * `br_corporate` (Subnet Range: 10.1.0.0/24)

## 3. Operational Evidence
The active provisioning state of the corporate range is verified below:
---

## 📄 Supplementary Technical Content
* Extended technical workflows and configuration exploits can be reviewed in our main English asset file: [tecnica.md](tecnica.md).


![Lab Deployment Evidence](lab_up.PNG)
